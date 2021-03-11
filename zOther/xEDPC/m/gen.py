#!/usr/bin/env python3

import random

n = 100
k = 10**5
print(n,k)
# lst = [str(random.randrange(0,k+1)) for _ in range(n)]
lst = [str(k) for _ in range(n)]
print(' '.join(lst))
