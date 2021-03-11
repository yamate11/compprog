#!/usr/bin/env python3

N, Q = map(int, input().strip().split())
vec = [0] * N
for _q in range(Q):
    l, r, t = map(int, input().strip().split())
    for i in range(l-1, r):
        vec[i] = t
for i in range(N):
    print(vec[i])
    
