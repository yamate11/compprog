#!/usr/bin/env python3

import random

n = 10**5
k = random.randrange(0,10**12+1)
print(n,k)
lst = [random.randrange(0,10**12+1) for _ in range(n)]
print(" ".join(map(str,lst)))

    
