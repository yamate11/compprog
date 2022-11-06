#!/usr/bin/env python3

x = []
for s in input().rstrip().split():
    if s == 'Left':
        x.append('<')
    elif s == 'Right':
        x.append('>')
    elif s == 'AtCoder':
        x.append('A')
print(' '.join(x))
