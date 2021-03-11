#!/usr/bin/env python

import random
from random import randrange 

N = 10
Q = 5

def main():
    print(N, Q)
    for i in range(2, N+1):
        j = randrange(1, i)
        c = randrange(1, N)
        d = randrange(1, 11)
        print(j, i, c, d)
    for i in range(Q):
        x = randrange(1, N)
        y = randrange(1, 11)
        u = randrange(1, N+1)
        while True:
            v = randrange(1, N+1)
            if u != v:
                break
            if u > v:
                u, v = v, u
        print(x, y, u, v)

main()

