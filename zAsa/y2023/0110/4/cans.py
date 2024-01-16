#!/usr/bin/env python3

N, K = map(int, input().split())
S = input()
v = ([0, 0] if S[0] == '0' else [0]) \
  + [i for i in range(1, N) if S[i] != S[i - 1]] \
  + ([N, N] if S[N - 1] == '0' else [N])
ans = N if len(v) < 2*K + 1 else \
    max([v[i + 2*K + 1] - v[i] for i in range(0, len(v) - 2*K, 2)])
print(ans)

