#!/usr/bin/env python3

N = 50

for y in range(1, N+1):
    for x in range(1, y+1):
        if y % x == y ^ x:
            print(y, x)
        
