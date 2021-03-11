#!/usr/bin/env python3

(N, K) = map(int, input().split())
r = N % K
print(min(r, K - r))
