#!/usr/bin/env python3

def fact(n):
    ret = 1.0;
    for i in range(1,n+1):
        ret *= i
    return ret

print(fact(10000))

