#!/usr/bin/env python3

tbl = {}

def check(p):
    if p in tbl:
        return tbl[p]
    (me, you, one, zero) = p
    if one == 0 and zero == 0:
        tbl[p] = you
        return you
    if one > 0:
        newP = (you, 1-me, one-1, zero)
        if check(newP) == 1:
            tbl[p] = 0
            return 0
    if zero > 0:
        newP = (you, me, one, zero-1)
        if check(newP) == 1:
            tbl[p] = 0
            return 0
    tbl[p] = 1
    return 1

for i in range(20):
    if i % 2 == 0:
        continue
    for j in range(6):
        print(i, j, check((0,0,i,j)))

