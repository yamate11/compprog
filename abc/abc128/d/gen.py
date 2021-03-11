#!/usr/bin/env python3

import random

n = 5
k = random.randrange(1,11)

print(n, k)
vs = [random.randrange(-10,10) for x in range(n)]
print(' '.join(map(str, vs)))
