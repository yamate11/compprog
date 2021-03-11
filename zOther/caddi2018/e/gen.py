#!/usr/bin/env python3

import random

n = 200000
lst = [str(random.randrange(1,10**9)) for _ in range(n)]
print(n)
print(' '.join(lst))

