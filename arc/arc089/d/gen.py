#!/usr/bin/env python3

import random

n = 10**5
k = 1000

print(n,k)
for i in range(n):
    x = random.randrange(10**9)
    y = random.randrange(10**9)
    c = 'BW'[random.randrange(2)]
    print(x, y, c)
