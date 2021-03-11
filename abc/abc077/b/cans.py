#!/usr/bin/env python3

N = int(input())
cand = 0
for i in range(N + 1):
    if i * i <= N:
        cand = i * i
    else:
        break
print(cand)
