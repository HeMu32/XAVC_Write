# Experiment 0012: Thumbnail rebuild with genuine 4:2:2 JPEG encoding

Date: 2026-06-25

## 问题

C0004T01、C0005T01 的缩略图被相机拒绝显示（仅显示为黑屏）。实验 0011 中尝试用 ffmpeg 的 `-pix_fmt yuvj422p` 输出 4:2:2 JPEG，但 ffmpeg 的 MJPEG encoder 实际仍编码为 4:2:0（SOF0 显示 Y=2x2），EXIF 却标注 YCbCrSubSampling=2 1（4:2:2），产生不匹配。后来改用 `tools/jpeg422.c`（libjpeg-turbo）编码为真正 4:2:2 后，Windows 能打开但内容完全错乱（亮粉色），因为色度数据被 Y 数据污染。

## 根因（两层）

1. **ffmpeg MJPEG encoder 不支持 4:2:2**：无论输入 `yuvj422p` 还是 `yuvj420p`，编码器内部始终以 4:2:0 处理（Y 采样因子 2x2）。Sony 相机很可能实际解析 JPEG 码流中的色度采样因子，而非仅依赖 EXIF。

2. **`jpeg_write_scanlines` 期望交织数据**：libjpeg-turbo 的 API 接收的是逐个像素排列 YCbCr 的交织（interleaved）格式。旧代码错误地传入了分离平面指针：
   ```c
   JSAMPROW row_pointer[3];
   row_pointer[0] = y_plane  + y * w;   // Y 平面行
   row_pointer[1] = cb_plane + y * w2;  // Cb 平面行
   row_pointer[2] = cr_plane + y * w2;  // Cr 平面行
   jpeg_write_scanlines(&cinfo, row_pointer, 1);
   ```
   这里 `row_pointer[3]` 被 libjpeg 解析为 3 个**不同行**的指针（而非 3 个平面），实际只读取 `row_pointer[0]` 指向的数据。结果 Y 被正确编码，Cb/Cr 被忽略（实际读的是 Y 平面后续字节），导致解码后呈亮粉色/紫红色。

## 修复内容

### 1. jpeg422.c — 交织缓冲区

```c
unsigned char *row_buffer = (unsigned char *)malloc(width * 3);
JSAMPROW row_pointer[1] = { row_buffer };

while (cinfo.next_scanline < cinfo.image_height) {
    int y = cinfo.next_scanline;
    for (int x = 0; x < width; x++) {
        row_buffer[x*3+0] = y_buf[y * width + x];
        row_buffer[x*3+1] = u_buf[y * (width/2) + x/2];
        row_buffer[x*3+2] = v_buf[y * (width/2) + x/2];
    }
    jpeg_write_scanlines(&cinfo, row_pointer, 1);
}
```

### 2. 组合 JPEG 文件结构

索尼缩略图文件是单 SOI/EOI 组合体：
```
SOI (文件级)
  APP1 (EXIF + 嵌入式 160×120 JPEG 缩略图数据)
    SOI (嵌入式缩略图)
    DQT DHT SOF0 SOS ... EOI
  DQT (主图像 1280×720 — 无自己的 SOI，复用文件级 SOI)
  DHT SOF0 SOS ... 
EOI (文件级)
```

关键约束：
- 主图像必须**去除**自己的 SOI/EOI（复用文件级 SOI/EOI）
- APP1 Length（偏移 4–5, BE）必须覆盖从偏移 4 到主图像起始
- IFD1 ThumbnailLength（偏移 692–695, LE）必须更新为嵌入式缩略图的实际大小
- DHT 段必须在 SOF0 之前（匹配相机顺序），通过 `Reorder-DHT` 函数后处理

### 3. 构建工作流

`tools/build_thumbnails.ps1` 自动化以下步骤：
1. `ffmpeg -ss 0 -i <clip> -vframes 1 -s 160x120 -pix_fmt yuvj422p -f rawvideo` 提取缩略图帧
2. `ffmpeg -ss 0 -i <clip> -vframes 1 -s 1280x720 -pix_fmt yuvj422p -f rawvideo` 提取主图帧
3. `jpeg422.exe` 将两帧分别编码为真正 4:2:2 JPEG
4. `Reorder-DHT` 后处理将 DHT 段移到 SOF0 之前
5. 从 C6359T01.JPG（相机模板）截取前 764 字节作为 EXIF 头
6. 拼接：EXIF 头 + 嵌入式缩略图 + 主图像（去除 SOI/EOI）+ 文件级 EOI
7. 更新 APP1 Length 和 IFD1 ThumbnailLength

## 验证

修复前解码结果：
- 输入：Y=211, Cb=128, Cr=126（浅灰）
- 解码后：Y=211, Cb=211, Cr=207（品红 — Cb/Cr 被 Y 数据污染）

修复后：
- 输入：Y=211, Cb=128, Cr=126（浅灰）
- 解码后：Y≈211, Cb≈128, Cr≈126（浅灰，±1 JPEG 损失）
- PSNR：~43.5 dB（quality=95，与参考帧高度一致）

SOF0 验证（真实 4:2:2）：

| 文件 | 采样因子 | 色度 |
|------|---------|------|
| C0004T01.JPG | Y:2x1 Cb:1x1 Cr:1x1 | 4:2:2 |
| C6359T01.JPG（相机） | Y:2x1 Cb:1x1 Cr:1x1 | 4:2:2 |

## 测试结果

- Windows 照片查看器：打开正常，内容正确
- Sony ILCE-7M4 相机：缩略图正确识别并显示

## 文件

- `tools/jpeg422.c` — YUV422→JPEG 编码器（libjpeg-turbo，交织数据，4:2:2）
- `tools/jpeg422.exe` — 编译好的可执行文件
- `tools/build_thumbnails.ps1` — 缩略图构建脚本（参数化：`build_thumbnails.ps1 C0004 [C0005 ...]`）
- `tools/thumb_header.bin` — 从 C6359T01.JPG 提取的 EXIF 头模板（764 字节，前 SOI + APP1/EXIF）
- `docs/patching-recipe.md` — 完整修补流程

## 经验教训

libjpeg-turbo 的 `jpeg_write_scanlines` 始终接收交织像素数据（逐个像素排列所有分量），即使用 `JCS_YCbCr` 作为输入颜色空间也不例外。库内部在编码前会根据采样因子进行色度下采样，但输入必须是完整分辨率、逐个像素交织的 YCbCr。

ffmpeg 的 MJPEG encoder 无法输出真实 4:2:2 JPEG。需要用 libjpeg-turbo、libjpeg 或其他支持自定义采样因子的 JPEG 库。

## 备选：exiftool 替代二进制拼接

当前的 `build_thumbnails.ps1` 通过 dump 固定 764 字节 + PowerShell 修补偏移来实现组合 JPEG。也可以用 `exiftool` 完成同样功能，避免硬编码偏移和模板文件：

### 原理

当前方案手动处理三个偏移字段：APP1 Length（文件偏移 4–5, BE）、ThumbnailOffset（IFD1 entry 偏移 680–683, LE）、ThumbnailLength（IFD1 entry 偏移 692–695, LE）。exiftool 在 `-ThumbnailImage<=thumb.jpg` 内部自动完成所有这些写入：

1. 从 main.jpg 复制所有原始标记（SOI → DQT → DHT → SOF0 → SOS → ... → EOI）
2. 在 SOI 后插入新 APP1/EXIF 段，其中包含：
   - TIFF 头（II 或 MM）
   - IFD0（自动生成必要标签）
   - IFD1（含 ThumbnailOffset、ThumbnailLength 等标签）
   - thumb.jpg 的完整内容（作为嵌入式缩略图）
3. 计算并写入：
   - **APP1 Length** = APP1 总大小（标记 + 长度字段 + "Exif\0\0" + TIFF 头 + IFD0 + IFD1 + 缩略图数据）
   - **ThumbnailOffset** = 缩略图数据起始位置相对 TIFF 头的偏移
   - **ThumbnailLength** = thumb.jpg 文件大小
4. 主图像标记紧跟 APP1 段，无自己的 SOI（复用文件级 SOI）

唯一的差异：exiftool 会在 IFD0 中添加少量自动标签（如 YCbCrPositioning），但这些不影响相机兼容性。

### 用法

```
jpeg422.exe thumb.yuv 160 120 thumb.jpg
jpeg422.exe main.yuv  1280 720 main.jpg
exiftool -overwrite_original "-ThumbnailImage<=thumb.jpg" main.jpg
copy /Y main.jpg C0004T01.JPG
Reorder-DHT C0004T01.JPG   （仍需要，exiftool 默认 DHT 在 SOF0 后）
```

### 差异对照

| 方面 | 当前实现 | exiftool 方案 |
|------|---------|---------------|
| EXIF 偏移 | 硬编码 4-5(APP1 Length), 692-695(ThumbnailLength) | exiftool 自动计算 |
| 模板依赖 | 需要 `thumb_header.bin`（764 字节） | 无模板依赖 |
| 外部依赖 | PowerShell `[System.IO.File]::ReadAllBytes` | exiftool 命令行 |
| DHT 顺序 | 后处理 `Reorder-DHT` | 同样需要 `Reorder-DHT` |
| APP0/JFIF | 无（jpeg422 不产生） | 无（exiftool 保留原图结构） |
| 缩略图控制 | 完全保留 jpeg422 输出 | exiftool 内部可能重编码缩略图 JPEG |

### 注意

- exiftool 在嵌入缩略图时**可能对缩略图 JPEG 进行转码**（取决于版本和输入格式），而非直接二进制复制。如果缩略图质量或色度采样被改变，需要用 `-ThumbnailImage<=` 配合 `-Binary` 等参数控制。
- 可以通过 `-Software="" -Make="" -Model=""` 去除 exiftool 可能添加的额外 EXIF 标签。
- 主图像 jpeg422 输出不含 APP1，exiftool 会添加 APP1/EXIF 段，主图像本身标记（DQT/DHT/SOF0/SOS）保持不变。
- 本文档记录方法的局限性: 缩略图虽然正确显示, 但是总是被相机纵向拉伸, 画面比例不正确. 