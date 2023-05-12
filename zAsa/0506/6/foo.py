#!/usr/bin/env python3

def binom(n, r):
    ret = 1.0
    while r > 0:
        ret *= n / r;
        n -= 1
        r -= 1
    return ret

print(binom(90, 30) * binom(60, 30) / (3.0 ** 90))

