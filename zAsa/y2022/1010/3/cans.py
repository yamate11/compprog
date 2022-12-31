#!/usr/bin/env python3
N, M = map(int, input().split())
cnt = [0] * N
for i in range(M):
    a, b = map(int, input().split())
    cnt[a - 1] += 1
    cnt[b - 1] += 1
cond1 = all((cnt[i] <= 2 for i in range(N)))
cond2 = any((cnt[i] < 2 for i in range(N)))
print("Yes" if cond1 and cond2 else "No")
