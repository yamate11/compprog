#!/usr/bin/env python

import random
from random import randrange 

N = 3
M = 5

def line(minValue, maxValueOne, len):
    '''Generates a line of integers from minValue to maxValueOne-1
    with length len'''
    lst = [str(randrange(minValue, maxValueOne)) for _ in range(len)]
    print(' '.join(lst))

def main():
    print(N, M)
    for i in range(M):
        a = randrange(100)
        cnt = 0
        bs = []
        for j in range(1, N+1):
            if random.random() < 0.5:
                bs.append(j)
                cnt += 1
        print(a, cnt)
        print(' '.join([str(b) for b in bs]))

main()

