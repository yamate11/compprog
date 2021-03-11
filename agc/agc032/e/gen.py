#!/usr/bin/env python3

import random

n = 10**5
m = 10**9

print(n, m)
lst = [str(random.randrange(m)) for _ in range(2*n)]
print(' '.join(lst))
