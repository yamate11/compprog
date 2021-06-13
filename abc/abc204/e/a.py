#!/usr/bin/env python3
import math

D = 1000
t0 = int((3 + math.sqrt(9 - 4 * (2 - D))) / 2.0 + 0.5)

def f(t):
    return t + D // (t + 1)

vmin = 1e10
prev = 1e10
stage = 0
for i in range(D):
    x = f(i)
    if x > prev:
        print(i, x)
        break
    prev = x

print(t0, f(t0))
