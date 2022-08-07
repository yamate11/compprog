#!/usr/bin/env python3

N = int(input())
s = [ord(c) - ord('a') for c in input().strip()]
pos = [[] for _ in range(26)]
ans = [None for _ in range(N)]
for i in range(len(s)):
    pos[s[i]].append(i)
p, q = 0, N - 1

def toChange():
    for c in range(s[p]):
        r = sub(c)
        if r is not None:
            return r
    return None

while p < q:
    r = toChange()
    if r is not None:
        for i in range(r + 1, q):
            ans[i] = s[i]
        ans[p] = s[r]
        ans[r] = s[p]
        q = r
    else:
        ans[p] = s[p]
    p += 1
