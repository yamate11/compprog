#!/usr/bin/env python3

import random

n = 10**5
m = 10**5

print(n,m)

ys = list(range(1, m+1))
random.shuffle(ys)
ps = [random.randrange(1,n+1) for i in range(m)]
for (y,p) in zip(ys, ps):
    print(p, y)
