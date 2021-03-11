#!/usr/bin/env python3

from random import randrange

N = int(2e5)
Q = int(2e5)

print(N, Q)

for q in range(Q):
    t = randrange(1, 3)
    if t == 1:
        x = randrange(1, N)
        y = 0
    else:
        while True:
            x = randrange(1, N+1)
            y = randrange(1, N+1)
            if x != y:
                if x > y:
                    x, y = y, x
                break
    print(t, x, y)
