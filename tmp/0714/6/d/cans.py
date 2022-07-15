#!/usr/bin/env python3

S = '*' + input().strip() + '*'
N = len(S) - 2
print(min([max(i, N - i) for i in range(N + 1) if S[i] != S[i + 1]]))
