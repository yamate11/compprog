#!/usr/bin/env python3

import random

n = 50
k = 10 ** 18
print(n,k)
for i in range(n):
    print(' '.join([str(random.randrange(0,2)) for _ in range(n)]))
          

