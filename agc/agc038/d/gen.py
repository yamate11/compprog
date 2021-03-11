#!/usr/bin/env python

import random
from random import randrange 

N = 5

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    M = randrange(N-1, N*(N-1)//2 + 1)
    Q = 0
    pp = 0.5
    abc = []
    for i in range(N-1):
        for j in range(i+1, N):
            if random.random() < pp:
                abc.append((i, j, randrange(2)))
                Q += 1
    print(N, M, Q)
    for (a,b,c) in abc:
        print(a, b, c)

main()

