#!/usr/bin/env python3

import random

n = 50
a = n // 2

xs = [random.randrange(1,n) for i in range(n)]

print(n,a)
print(' '.join(map(str,xs)))

    
