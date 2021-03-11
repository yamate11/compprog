#!/usr/bin/env python3

N = int(input())
sum = 0
for i in range(1, N+1):
    if i % 3 != 0 and i % 5 != 0:
        sum += i
print(sum)
