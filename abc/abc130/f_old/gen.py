#!/usr/bin/env python3

import random

vlim = 100000000
np = 20
print(np)
for i in range(np):
    x = random.randrange(-vlim, vlim+1)
    y = random.randrange(-vlim, vlim+1)
    d = random.choice("RLUD")
    print(x, y, d)
    
