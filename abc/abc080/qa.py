#!/usr/bin/python3

import sys

line = sys.stdin.readline()
n, a, b = [int(x) for x in line.rstrip().split(' ')]
if n * a <= b:
    print(n * a)
else:
    print(b)

