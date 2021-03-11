#!/usr/bin/env python3

import random

lst = ['i' if random.random() < 2.0/3.0 else 'w' for i in range(300)]
print(''.join(lst))
