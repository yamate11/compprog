#!/usr/bin/env python3

import math

N = int(input())
T = list(map(int, input().split()))

x = T[0]
for i in range(1, N):
    x = math.lcm(x, T[i])
x //= T[0]
print(f'{x}/1')

    
