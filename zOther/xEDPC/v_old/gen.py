#!/usr/bin/env python3

import random

n = 10**5
m = 10**7 + 9
print(n,m)
for i in range(1,n):
    j = random.randrange(0,max(1,i // 3))
    print(j+1,i+1)
