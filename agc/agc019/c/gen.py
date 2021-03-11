#!/usr/bin/env python3

import random

lim = 10**8
n = 200000

x1 = 0
y1 = 0
x2 = lim - 1
y2 = lim - 1
xs = set()
ys = set()
print(x1,y1,x2,y2)
print(n)
for i in range(n):
    while True:
        x = random.randrange(0,lim)
        y = random.randrange(0,lim)
        if x in xs or y in ys:
            continue
        if (x,y) == (x1,y1) or (x,y) == (x2,y2):
            continue
        break
    xs.add(x)
    ys.add(y)
    print(x,y)
    
