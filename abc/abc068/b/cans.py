#!/usr/bin/env python3


N = int(input())

ans = 0
amax = -1
for x in range(1, N+1):
    cnt = 0
    y = x
    while y % 2 == 0:
        cnt += 1
        y /= 2
    if cnt > amax:
        ans = x
        amax = cnt
print(ans)

