#!/usr/bin/python3

import math

N, Q = map(int, input().split())
XRH = [list(map(int, input().split())) for _ in range(N)]

def f(t):
    ret = 0
    for i in range(N):
        (x, r, h) = XRH[i]
        vol = math.pi / 3 * r * r * h
        p = max(0, min(1, (x + h - t) / h))
        ret +=  p * p * p * vol;
    return ret

for _ in range(Q):
    A, B = map(int, input().split())
    print(f(A) - f(B))
