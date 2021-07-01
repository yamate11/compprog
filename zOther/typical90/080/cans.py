#!/usr/bin/env python3

import numpy as np

N, D = map(int, input().split())
A = [int(a) for a in input().split()]
M1 = [sum([1 << i for i in range(N) if (A[i] >> j) & 1])
     for j in range(D)]
M = np.array(M1)
memo = -np.ones((D + 1) * (1 << N), dtype=int).reshape(D + 1, 1 << N)

def cnt(d, x):
    if memo[d][x] < 0:
        if x == 0:
            memo[d][x] = 1 << d
        elif d == 0:
            memo[d][x] = 0
        else:
            memo[d][x] = cnt(d-1, x) + cnt(d-1, x & ~M[d-1])
    return memo[d][x]

print(cnt(D, (1<<N) - 1))
