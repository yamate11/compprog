#!/usr/bin/env python3

import sys

def solve(n, x, ms):
    sumM = 0
    minM = 1000
    for m in ms:
        sumM += m
        if m < minM:
            minM = m
    add = (x - sumM) // minM
    return n + add

def readQuestion():
    line = sys.stdin.readline()
    sline = line.rstrip()
    str_n, str_x = sline.split(' ')
    n = int(str_n)
    x = int(str_x)
    ms = []
    for line in sys.stdin:
        sline = line.rstrip()
        m = int(sline)
        ms.append(m)
    return (n, x, ms)

def main():
    (n, x, ms) = readQuestion()
    ans = solve(n, x, ms)
    print(ans)

if __name__ == '__main__':
    main()
