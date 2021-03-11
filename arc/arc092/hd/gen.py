#!/usr/bin/env python3

import random

n = 200000
r = 2**28

print(n)
a = [random.randrange(r) for i in range(n)]
b = [random.randrange(r) for i in range(n)]
print(' '.join(map(str,a)))
print(' '.join(map(str,b)))

