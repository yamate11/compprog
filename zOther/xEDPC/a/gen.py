#!/usr/bin/env python3

import random

n = 10**5
print(n)
print(' '.join([str(random.randrange(1,10**4+1)) for _ in range(n)]))
