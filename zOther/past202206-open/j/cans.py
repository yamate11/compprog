#!/usr/bin/env python3

import sys
from datetime import date, timedelta

def f(d):
    base = date(2021, 12, 31) # Friday
    x = d.toordinal() - base.toordinal()
    y = x // 7
    z = x % 7
    add = 0
    if z == 1:
        add = 1
    elif z >= 2:
        add = 2
    r = y * 2 + add
    print(d, y, z, add, r, file=sys.stderr)
    return r

def main():
    S = input()
    T = input()
    ds = date(int(S[0:4]), int(S[5:7]), int(S[8:10])) - timedelta(days=1)
    dt = date(int(T[0:4]), int(T[5:7]), int(T[8:10]))
    print(f(dt) - f(ds))
    


main()
