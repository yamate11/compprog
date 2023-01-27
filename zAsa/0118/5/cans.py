#!/usr/bin/env python3

N, C = map(int, input().split())
lim = 10**5 + 1
vec = [[0 for c in range(C)] for j in range(lim)]
for i in range(N):
    s, t, c = map(int, input().split())
    for j in range(s, t + 1):
        vec[j][c - 1] = 1
print(max(map(sum, vec)))
