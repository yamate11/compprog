#!/usr/bin/env python3

import sys


def f(n, k):
    if k == 0 and n == 0:
        return "b"
    elif k == 0 and n == 1:
        return "a"
    elif n >= 2 and 0 <= k and k < (1 << (n - 1)) and k % 2 == 0:
        return f(n - 1, k // 2) + f(n - 2, k // 4)
    elif n >= 2 and 0 <= k and k < (1 << (n - 1)) and k % 2 == 1:
        return f(n - 2, k // 4) + f(n - 1, k // 2)
    else:
        print("NG", n, k)

for n in range(6):
    for k in range(16):
        print(n, k, f(n, k))
