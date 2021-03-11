#!/usr/bin/env python3

from random import randrange

def main():
    n = 200000
    m = 200000
    k = 200000
    lst = [randrange(1, k + 1) for _ in range(n)]
    print(n, m, k)
    print(' '.join(map(str, lst)))
    for _ in range(m):
        x, y = 0, 0
        while x == y:
            x = randrange(1, n + 1)
            y = randrange(1, n + 1)
        print(x, y)

main()
