#!/usr/bin/env python3

import random

n = 299999
print(n)
lst = [str(random.randrange(1,1001)) for i in range(n)]
print(' '.join(lst))
