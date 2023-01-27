#!/usr/bin/env python3

import random

n = 2*10**5
oa = ord('a')
lst = [chr(random.randrange(oa, oa+26)) for _ in range(n)]
print(''.join(lst))
