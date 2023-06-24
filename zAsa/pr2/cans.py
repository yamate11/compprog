#!/usr/bin/env pypy3

import sys

def debug(*msg):
    print(*msg, file=sys.stderr)

def intdec(x):
    return int(x) - 1

N, M, K = map(int, input().strip().split())
S = list(map(intdec, input().strip().split()))
A = list(map(int, input().strip().split()))
B = list(map(int, input().strip().split()))

rec = [-1 for _ in range(M + 1)]
prev = [0 for _ in range(N)]
for i in range(N):
    prev[i] = rec[S[i]]
    rec[S[i]] = i
debug(prev)

primeB = 998244353

acc = [[0 for k in range(K + 1)] for n in range(N + 1)]
acc[0][0] = 1
for i in range(N):
    acc[i + 1] = acc[i][:]
    for k in range(K + 1):
        exc = 0 if prev[i] < 0 else acc[prev[i]][k]
        v = (acc[i][k] - exc) % primeB
        a1 = k + A[S[i]]
        if a1 <= K:
            acc[i + 1][a1] = (acc[i + 1][a1] + v) % primeB
        b1 = k + B[S[i]]
        if b1 <= K:
            acc[i + 1][b1] = (acc[i + 1][b1] + v) % primeB
    debug(acc[i + 1])

print(acc[N][K])
