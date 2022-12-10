#!/usr/bin/env python3

import sys

N, K = map(int, input().split())
S = input().strip()

def debug(*msg):
    print(*msg, file=sys.stderr)

def winner(c1, c2):
    if (c1, c2) in [('R','P'), ('P','S'), ('S','R')]:
        return c2
    return c1

rec = [[None for i in range(N)] for j in range(K + 1)]
rec[0] = [S[i] for i in range(N)]

def f(k, i):
    i = i % N
    if rec[k][i] is None:
        rec[k][i] = winner(f(k - 1, 2 * i), f(k - 1, 2 * i + 1))
    return rec[k][i]

print(f(K, 0))
debug(rec)
