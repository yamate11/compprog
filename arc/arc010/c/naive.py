#!/usr/bin/env python3

import sys

def subs(s):
    ll = len(s)
    return ((s[j] for j in range(ll) if ((x >> j) & 1))
            for x in range(1 << ll))

N, M, Y, Z = map(int, input().split())
val = {}
for i in range(M):
    c, p = input().split()
    val[c] = int(p)

def strval(s):
    ccnt = 0
    cset = set()
    prev = ''
    cont = 1
    tot = 0
    for c in s:
        tot += val[c]
        if c == prev:
            cont += 1
        else:
            tot += (cont - 1) * Y
            cont = 1
        prev = c
        if c not in cset:
            ccnt += 1
            cset.add(c)
    tot += (cont - 1) * Y
    if ccnt == M:
        tot += Z
    return tot

B = input().rstrip()
vmax = 0
for s in subs(B):
    s = list(s)
    tot = strval(s)
    # print(s, tot)
    vmax = max(vmax, tot)
print(vmax)


