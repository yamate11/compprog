#!/usr/bin/env python3

from random import randrange

N = 200000

print(N)
for i in range(N):
    a = randrange(1, 2 * N)
    b = randrange(1, 2 * N)
    print(a, b)
    
