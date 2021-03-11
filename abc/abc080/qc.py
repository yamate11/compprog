#!/usr/bin/python3

import sys

def main():
    line = sys.stdin.readline()
    n = int(line.rstrip())
    f = [None for i in range(n)]
    p = [None for i in range(n)]
    for i in range(n):
        line = sys.stdin.readline()
        f[i] = getFn([int(x) for x in line.rstrip().split(' ')])
        # print('f', i, f[i])
    for i in range(n):
        line = sys.stdin.readline()
        p[i] = [int(x) for x in line.rstrip().split(' ')]
    vMax = None
    for t in range(1, 1024):
        s = 0
        for i in range(n):
            common = countBit(f[i] & t)
            s += p[i][common]
        if vMax is None or vMax < s:
            vMax = s
    print(vMax)

def getFn(f):
    s = 0
    for b in f:
        s = (s << 1) | b
    return s

def countBit(c):
    s = 0
    while c > 0:
        if c & 1 == 1:
            s += 1
        c >>= 1
    return s

if __name__ == '__main__':
    main()


    
