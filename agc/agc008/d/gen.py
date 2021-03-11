#!/usr/bin/env python3

from random import randrange

N = 3
print(N)
a = [-1 for _ in range(N)]
for i in range(N):
    while True:
        x = randrange(1, N*N+1)
        if x not in a: break
    a[i] = x
print(' '.join(map(str, a)))

