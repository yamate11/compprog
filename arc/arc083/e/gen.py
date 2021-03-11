#!/usr/bin/env python3

import random

n = 1000
ps = [random.randrange(1,i) for i in range(2,n+1)]
xs = [random.randrange(0,5001) for _ in range(n)]
print(n)
print(' '.join(map(str,ps)))
print(' '.join(map(str,xs)))
