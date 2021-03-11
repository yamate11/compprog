#!/usr/bin/env python3

import random

n = 3000

lst1 = [chr(97 + random.randrange(26)) for _ in range(n)]
lst2 = [chr(97 + random.randrange(26)) for _ in range(n)]
s = ''.join(lst1)
t = ''.join(lst2)
print(s)
print(t)
