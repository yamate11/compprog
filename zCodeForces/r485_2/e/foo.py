#!/usr/bin/env python3

from random import randrange

def main():
    n = 1005
    A = list(range(n))
    for i in range(3*n):
        while True:
            x = randrange(n)
            y = randrange(n)
            if x != y:
                break
        A[x], A[y] = A[y], A[x]
    B = list(range(n))
    for i in range(7*n + 1):
        while True:
            x = randrange(n)
            y = randrange(n)
            if x != y:
                break
        B[x], B[y] = B[y], B[x]

    cntA = 0
    cntB = 0
    for i in range(n):
        for j in range(i + 1, n):
            if A[i] > A[j]:
                cntA += 1
            if B[i] > B[j]:
                cntB += 1
    print(cntA, cntB)


main()
