#!/usr/bin/env python3

import sys

def solve(n, m, x, aa):
    left = 0
    right = 0
    on_left = True
    for i in range(n):
        if i in aa:
            if on_left:
                left += 1
            else:
                right += 1
        if i == x:
            on_left = False
    if left < right:
        return left
    else:
        return right

def readQuestion():
    line = sys.stdin.readline()
    sline = line.rstrip()
    (str_n, str_m, str_x) = sline.split(' ')
    n = int(str_n)
    m = int(str_m)
    x = int(str_x)
    line = sys.stdin.readline()
    sline = line.rstrip()
    str_as = sline.split(' ')
    aa = []
    for str_a in str_as:
        aa.append(int(str_a))
    return (n, m, x, aa)

def main():
    n, m, x, aa = readQuestion()
    ans = solve(n, m, x, aa)
    print(ans)

if __name__ == '__main__':
    main()
