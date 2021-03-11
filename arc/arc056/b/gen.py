#!/usr/bin/env python

import random
from random import randrange 

N = 7
Q = 5
aLim = 10
xLim = 30

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    N = 3
    M = 3
    S = randrange(1, N+1)
    print(N, M, S)
    ps = set()
    k = 0
    while k < M:
        while True:
            while True:
                u = randrange(1, N+1)
                v = randrange(1, N+1)
                if u != v: break
            if (u,v) not in ps: break
        ps.add((u,v))
        k += 1
    for p in ps:
        print(p[0], p[1])
        
main()

