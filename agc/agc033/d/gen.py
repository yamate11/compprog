#!/usr/bin/env python3

import random

h = 3
w = 3

def func():
    if random.randrange(2) == 0:
        return '.'
    return '#'

print(h, w)
for y in range(h):
    line = ''.join([func() for _ in range(w)])
    print(line)
    
