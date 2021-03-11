#!/usr/bin/env python3

import sys

def solve(a, b, x):
    if a <= x and x <= a + b:
        return 'YES'
    else:
        return 'NO'

def readQuestion():
    line = sys.stdin.readline()
    sline = line.rstrip()
    (str_a, str_b, str_x) = sline.split(' ')
    a = int(str_a)
    b = int(str_b)
    x = int(str_x)
    return (a, b, x)

def main():
    a, b, x = readQuestion()
    ans = solve(a, b, x)
    print(ans)

if __name__ == '__main__':
    main()
