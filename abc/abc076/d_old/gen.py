#!/usr/bin/env python3

from random import randrange

N = 60
ts = [0] * N
vs = [0] * N
for i in range(N):
    ts[i] = randrange(1,100)
    vs[i] = randrange(1,100)
print(N)
print(' '.join(map(str,ts)))
print(' '.join(map(str,vs)))
