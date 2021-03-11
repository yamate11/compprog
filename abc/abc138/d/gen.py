#!/usr/bin/env python

import random
from random import randrange 

N = 4*10**5
Q = 4*10**5

def main():
    print(N, Q)
    for i in range(2, N+1):
        j = randrange(1, i)
        print(j, i)
    for i in range(Q):
        print(randrange(1, N+1), randrange(1, 10001))

main()

