#!/usr/bin/env python3

N, M = map(int, input().split())

v = 0
ans = -1
for i in range(N):
    v = 10 * v + 1
    for k in range(1, 10):
        t = k * v
        if t % M == 0:
            ans = max(ans, t)
print(ans)

