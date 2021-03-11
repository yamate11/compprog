#!/usr/bin/env python3

import random

n = 200000
h = n
w = n
s = set()

lst = []
for i in range(n):
    while True:
        x = random.randrange(1,h+1)
        y = random.randrange(1,w+1)
        if (x,y) not in s:
            s.add((x,y))
            lst.append((x,y))
            break
print(h, w, n)
for (x,y) in lst:
    print('{} {}'.format(x,y))




