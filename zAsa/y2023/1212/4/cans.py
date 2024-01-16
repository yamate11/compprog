#!/usr/bin/env python3

import re

def main():
    S = input().split()
    N = int(input())
    ws = []
    for i in range(N):
        t = input()
        ws.append(t)
    # print(ws)
    ans = []
    for s in S:
        for t in ws:
            if re.match(t.replace('*', '.') + '$', s):
                s = '*' * len(s)
                break
        ans.append(s)
    print(' '.join(ans))

main()
