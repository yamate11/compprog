#!/usr/bin/env python3

import random

n = 2*10**5
lstA = [random.randrange(0,10**9+1) for _ in range(n)]
print(n)
print(' '.join(map(str,lstA)))
