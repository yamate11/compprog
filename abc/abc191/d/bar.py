#!/usr/bin/env python3

from decimal import *

getcontext().prec = 20

for p in range(1000):
    x = Decimal(p) ** Decimal(0.5)
    y = Decimal(4 * p) ** Decimal(0.5)
    if x + x < y:
        print(p, x)
        break
