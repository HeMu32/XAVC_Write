"""Purpose: query local DeepSeek Harness sessions or send an authorized prompt.

Usage: python tools/dsh_client.py list; use status/page --session ID, or prompt
    --session ID --file PROMPT.txt; optionally save results with --output FILE.
Design: authenticate through the local DSH launch log and call its HTTP RPC API
    without printing the launch token; page requests use projection sequence IDs.
Scope: the installed localhost DSH instance and its current API. Prompt sends
    change another session and require user authorization; read actions do not.
"""
import argparse
import json
import re
import sys
import uuid
from pathlib import Path

import requests


def main():
    sys.stdout.reconfigure(encoding="utf-8")
    ap = argparse.ArgumentParser()
    ap.add_argument("action", choices=["list", "status", "page", "prompt"])
    ap.add_argument("--session")
    ap.add_argument("--file")
    ap.add_argument("--output")
    ap.add_argument("--messages", type=int, default=12)
    ap.add_argument("--cwd")
    args = ap.parse_args()
    log = Path("E:/Program Files/dsh/web.out.log").read_text(encoding="utf-8", errors="replace")
    urls = re.findall(r"http://127\.0\.0\.1:3080/\?token=\S+", log)
    if not urls:
        raise SystemExit("No local DSH launch URL")
    s = requests.Session()
    s.get(urls[-1], timeout=15).raise_for_status()

    def rpc(method, arguments):
        body = {"type": "client-request", "rpcId": str(uuid.uuid4()),
                "method": method, "payload": {"args": arguments}}
        r = s.post("http://127.0.0.1:3080/api/" + method, json=body, timeout=60)
        r.raise_for_status()
        result = r.json()["result"]
        if not result["ok"]:
            raise RuntimeError(result.get("error", {}).get("code", "DSH RPC failed"))
        return result["value"]

    if args.action == "list":
        result = rpc("session/list", {"_request": {}})
        result = [{"id": x["sessionId"], "cwd": x.get("cwd"), "running": x.get("running"),
                   "title": x.get("projections", {}).get("values", {}).get("title")}
                  for x in result["items"] if not args.cwd or args.cwd.lower() in x.get("cwd", "").lower()]
    elif args.action == "prompt":
        text = Path(args.file).read_text(encoding="utf-8")
        result = rpc("session/prompt", {"request": {
            "sessionId": args.session, "requestId": str(uuid.uuid4()), "mode": "queue",
            "content": [{"type": "text", "text": text}], "clientTimeZone": "Asia/Shanghai"}})
    else:
        result = rpc("session/projections", {"request": {"sessionId": args.session}})
        if args.action == "page":
            result = rpc("session/page", {"request": {
                "address": {"kind": "session", "sessionId": args.session},
                "throughSeq": result["asOfSeq"], "maxMessages": args.messages}})
    text = json.dumps(result, ensure_ascii=False, indent=2)
    if args.output:
        out = Path(args.output)
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_text(text, encoding="utf-8")
        print(str(out.resolve()))
    else:
        print(text)


if __name__ == "__main__":
    main()
