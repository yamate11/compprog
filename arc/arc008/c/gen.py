#!/usr/bin/env python3

from random import randrange

N = 1000
print(N)
for i in range(N):
    x = randrange(-100, 100)
    y = randrange(-100, 100)
    t = randrange(3, 341)
    r = randrange(3, 341)
    print (x, y, t, r)
