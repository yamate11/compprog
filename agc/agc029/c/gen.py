#!/usr/bin/env python3

import random

n = 2 * (10 ** 5)
m = 10 ** 9

print(n)
print(' '.join([str(random.randrange(1,m)) for _ in range(n)]))
