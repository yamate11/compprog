#!/usr/bin/env python3

import sys

def solve(bigN, bigX, xs):
    ys = [abs(x - bigX) for x in xs]
    g = ys[0]
    for y in ys[1:]:
        g = gcd(y, g)
    return g

def gcd(a, b):
    '''The greatest common divisor of a and b.'''
    while b > 0:
        (a, b) = (b, a % b)
    return a

def readQuestion():
    [line1, line2] = list(sys.stdin)
    [bigN, bigX] = [int(s) for s in line1.split(' ')]
    xs           = [int(s) for s in line2.split(' ')]
    return (bigN, bigX, xs)

def main():
    bigN, bigX, xs = readQuestion()
    answer = solve(bigN, bigX, xs)
    print(answer)
    
if __name__ == '__main__':
    main()
