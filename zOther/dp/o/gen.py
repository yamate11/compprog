#!/usr/bin/env python3

import random

n = 21
# lst = [[random.randrange(0,2) for _ in range(n)] for _ in range(n)]
lst = [[1 for _ in range(n)] for _ in range(n)]
print(n)
for i in range(n):
    print(' '.join(map(str,lst[i])))
    

