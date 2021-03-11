#!/usr/bin/env python3

from random import randrange
import math

N = 1000000

print(N)
for i in range(2, N+1):
    j = randrange(i - int(math.sqrt(i)), i)
    print (j, i)
    
