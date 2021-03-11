#!/usr/bin/env python3

import random

N = 13
with open("xxx") as fp:
    K = int(fp.readline())
with open("xxx", "w") as fp:
    print(K+1, file=fp)
print(N, K)
