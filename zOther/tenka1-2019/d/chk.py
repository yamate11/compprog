#!/usr/bin/env python3

import sys, math

n = 998244355

for i in range(2, 1 + int(math.sqrt(n))):
    if n % i == 0:
        print(f'divided by {i}');
        sys.exit(0);
print('prime')

