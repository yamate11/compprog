#!/usr/bin/env python3

import itertools

lst = [0,0,1,1,2,2,3,3]

for p in itertools.permutations(lst):
    for k in [0,1,2,3]:
        x = 0
        f = False
        for i in range(8):
            if p[i] == k and not f:
                f = True
            if p[i] == k and f:
                break
            if f:
                x = x ^ p[i]
