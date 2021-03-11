#!/usr/bin/env python3

from random import randrange


T = 1
print(T)

for t in range(T):
    # N = randrange(1, 10)
    N = 4
    vec = []
    S = ''
    for _ in range(N):
        if randrange(2) == 0:
            S += '0'
            vec.append(randrange(1, 1<<3))
        else:
            S += '1'
            vec.append(2)
    print(N)
    print(' '.join(map(str,vec)))
    print(S)
