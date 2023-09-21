#!/usr/bin/env python3

from sortedcontainers import SortedList
from collections import deque


N, K = map(int, input().split())
P = list(map(int, input().split()))

ans = [-1] * N
SL = SortedList(key=lambda x: x[-1])

for i in range(N):
    bis = SL.bisect_left([P[i]])
    if bis >= len(SL):
        if K == 1:
            ans[P[i] - 1] = i + 1
        else:
            SL.add(deque([P[i]]))
    else:
        if len(SL[bis]) == K - 1:
            for j in SL[bis]:
                ans[j - 1] = i + 1
            ans[P[i] - 1] = i + 1
            SL.pop(bis)
        else:
            q = SL[bis]
            SL.pop(bis)
            q.append(P[i])
            SL.add(q)

for i in range(N):
    print(ans[i])
