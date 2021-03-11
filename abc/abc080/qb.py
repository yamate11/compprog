#!/usr/bin/python3

import sys

line = sys.stdin.readline()
n = int(line.rstrip())

s = 0
x = n
while x > 0:
    x, r = (x // 10, x % 10)
    s += r
print(n, s, n % s)
print('Yes' if n % s == 0 else 'No')


