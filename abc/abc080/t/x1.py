#!/usr/bin/python3

import random


n = 500000
with open('data1.txt', 'w') as f:
    for i in range(n):
        f.write(str(random.choice(range(1000)))+'\n')

n = 1000000
with open('data2.txt', 'w') as f:
    for i in range(n):
        f.write(str(random.choice(range(1000)))+'\n')

n = 2000000
with open('data3.txt', 'w') as f:
    for i in range(n):
        f.write(str(random.choice(range(1000)))+'\n')


