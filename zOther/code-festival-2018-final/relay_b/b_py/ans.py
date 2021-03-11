#!/usr/bin/env python3

import sys, itertools

dic = {'W': 0, 'X': 1, 'Y': 2, 'Z': 3}

def pShift(t1, t2):
    (x1, y1) = t1
    (x2, y2) = t2
    return (x1 + x2, y1 + y2)

def check(t):
    if t == (gx, gy):
        print('Yes')
        sys.exit(0)

def main():
    global gx, gy
    [line1, line2] = [line for line in sys.stdin]
    s = line1.strip()
    [gx, gy] = map(int, line2.split())
    for p in itertools.permutations([(1,0),(-1,0),(0,1),(0,-1)]):
        t = (0,0)
        check(t)
        for c in s:
            t = pShift(t, p[dic[c]])
            check(t)
    print('No')

main()
