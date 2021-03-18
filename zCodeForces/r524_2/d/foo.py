#!/usr/bin/env python3

import sys

# for m in range(40):
#     x = 2**m - 1
#     xx = (4**m - 1) / 3 + x*x
#     boo = xx > 10**18
#     print(m, xx, boo)


# sys.exit(1)

for n in range(10):
    t = 0
    for i in range(n):
        t += 2 ** (i + 1) - 1
    s = 0
    for i in range(n):
        s += 2 ** (2 * i)
    s += (2 ** n - 1) * (2 ** n - 1)
    print(n, t, s)
