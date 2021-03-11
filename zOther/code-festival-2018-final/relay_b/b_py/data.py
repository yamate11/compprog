#!/usr/bin/env python3

import random

n = 10 ** 5
for c in range(n):
    print(random.choice('WXYZ'), end='')
print()
print(random.randrange(2*n) - n, random.randrange(2*n) - n)
