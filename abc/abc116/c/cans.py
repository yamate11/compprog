#!/usr/bin/env python3

import sys

def func(H, l, r):
    hmin = 1000
    for x in range(l, r):
        hmin = min(hmin, H[x])
    vec = [l - 1]
    for x in range(l, r):
        H[x] -= hmin
        if H[x] == 0:
            vec.append(x)
    vec.append(r)
    ret = hmin
    for i in range(len(vec) - 1):
        if vec[i] + 1 < vec[i + 1]:
            ret += func(H, vec[i] + 1, vec[i + 1])
    print("l,r,ret=", l, r, ret, file=sys.stderr)
    return ret

def main():
    N = int(input())
    H = list(map(int, input().strip().split()))
    print(func(H, 0, N))

main()
