#!/usr/bin/env python3

L = input().strip().split()
a = ['<' if t == 'Left' else '>' if t == 'Right' else 'A'
     for t in L]
print(' '.join(a))

