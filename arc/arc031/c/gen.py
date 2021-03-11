#!/usr/bin/env python3

import random

N = 6
lst = list(range(1, N+1))
random.shuffle(lst)
print(N)
print(' '.join([str(i) for i in lst]))
