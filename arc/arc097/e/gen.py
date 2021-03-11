#!/usr/bin/env python3

import random, sys

n = int(sys.argv[1])
x = ['{} {}'.format('B', i) for i in range(1,n+1)] + \
    ['{} {}'.format('W', i) for i in range(1,n+1)]
random.shuffle(x)
print(n)
print('\n'.join(x))

