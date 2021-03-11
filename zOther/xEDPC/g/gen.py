#!/usr/bin/env python3

import random

n = 10**5
m = 10**5
xys = []
for j in range(m):
    x, y = 0, 0
    while x == y:
        x = random.randrange(1, n+1)
        y = random.randrange(1, n+1)
    if x > y:
        x, y = y, x
    xys.append((x,y))
print(n, m)
for (x,y) in xys:
    print(x, y)
