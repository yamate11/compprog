#!/usr/bin/env python3

import random

h = 500
w = 500

with open('d9.txt', 'w') as fp:
    print(h, w, file=fp)
    for y in range(h):
        print(' '.join([str(random.randrange(10)) for x in range(w)]),
              file=fp)

        
