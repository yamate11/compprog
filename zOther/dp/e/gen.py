#!/usr/bin/env python3

import random

n = 100
w = 10**9
print(n,w)
for _ in range(n):
    print('{} {}'.format(random.randrange(1,w+1), random.randrange(1,1001)))
