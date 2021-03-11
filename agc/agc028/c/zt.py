#!/usr/bin/env python3

import random

n = 10**5
m = 10**5
print(n, m)
ps = [str(random.randrange(10**9)) for i in range(n)]
print(' '.join(ps))
for k in range(m):
    x = random.randrange(10**9)
    y = random.randrange(10**9)
    print(x,y)
