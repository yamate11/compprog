#!/usr/bin/env python3

import random
from random import randrange

N = randrange(1, 10)
d = randrange(1, 10)
x0 = randrange(-9, 10)
y0 = randrange(-9, 10)
x0 = y0 = 0
print(N)
for i in range(N):
    ss = set()
    while True:
        dx = randrange(-d, d+1)
        dy = d - dx
        if random.random() < 0.5:
            dy = -dy
        x = x0 + dx
        y = y0 + dy
        if not (x, y) in ss:
            ss.add((x, y))
            print(x, y)
            break

