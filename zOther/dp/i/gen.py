#!/usr/bin/env python3

import random

n = 2999
lst = [str(random.randrange(1,100)/100) for _ in range(n)]
print(n)
print(' '.join(lst))

