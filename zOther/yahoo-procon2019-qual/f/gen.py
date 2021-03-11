#!/usr/bin/env python3

import random

n = 2000
s = ""
for i in range(n):
    c = str(random.randrange(0,3))
    s += c
print(s)

