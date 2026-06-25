看到K:\ 这是一个Sony相机的存储卡. 我们需要分析它的视频编录格式. 

在每次分析之前, 备份/创建snapshot其中的文件到.\backup\, 除了图片, 视频文件外.  对于不备份的文件, 记录其时间信息以便做粗略的差异分析. 备份之前访问既有的Snapshot来了解它应有的格式. 

.\docs\下存有对当前进展的总结. 需要注意文档不等于绝对可靠, 这是纯粹对更改进行分析得出的内容和推断, 随时可能被后续结论推翻. 

path中有ffmpeg和exiftool. 你可能会用得到. 

path中有mingw, 偶尔你可能会需要做精确操作或者比对. 避免用pwsh, 因为它可能有bug或者你不熟练. 不要使用python, 这里没有python. 

\include\ffmpeg\include 下有ffmpeg的头文件. \include\ffmpeg\lib 下有链接文件. 
ffmpeg的二进制 (dlls) 已经在系统path. 