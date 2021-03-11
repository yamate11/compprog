#!/usr/bin/env python3

import random

n = 1000
xs = [str(random.randrange(-10**6,10**6)) for _ in range(n)]
print(n)
print(' '.join(xs))
