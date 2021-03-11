#!/usr/bin/env python3

from random import randrange

def mex(x, y):
    if x != 0 and y != 0:
        return 0
    elif x != 1 and y != 1:
        return 1
    else:
        return 2

def showlist(x):
    print(''.join(map(str, x)))

def main():
    n = 10
    x = [randrange(3) for _ in range(n)]
    y = [randrange(3) for _ in range(n)]
    showlist(x)
    showlist(y)
    print()
    for i in range(n):
        x[0] = mex(x[0], y[i])
        for j in range(n - 1):
            x[j+1] = mex(x[j+1], x[j])
        showlist(x)


main()
