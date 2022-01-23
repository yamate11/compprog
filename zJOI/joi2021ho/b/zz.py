#!/usr/bin/env python3

from random import randrange

def main():
    N = 500000
    Q = 500000
    sc = 100
    X = []
    x = randrange(-sc * N, 0)
    for i in range(N):
        X.append(x)
        x += randrange(1, sc)
    W = [randrange(-sc * N, sc * N) for i in range(Q)]
    print(N, Q)
    print(' '.join([str(x) for x in X]))
    for w in W:
        print(w)

main()
