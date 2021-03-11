#!/usr/bin/env python3

import random

n = 10**5
print(n)
for i in range(2,n+1):
    p = random.randrange(1,i)
    print(p,i)
