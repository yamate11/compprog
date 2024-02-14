#!/usr/bin/env python3

N = int(input())
A = list(map(int, input().split()))

ans = 0
for i in range(N):
    vmin = 10**18
    for j in range(i, N):
        vmin = min(vmin, A[j])
        ans = max(ans, vmin * (j - i + 1))
print(ans)
