#!/usr/bin/env python3

dic = {s: str(i // 2) for (i, s) in enumerate("zrbcdwtjfqlvsxpmhkng")}
n = int(input())
a = map(lambda x: x.lower(), input().split())
o = [''.join([dic.get(c, '') for c in w]) for w in a]
print(*[s for s in o if s])

