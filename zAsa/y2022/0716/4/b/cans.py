#!/usr/bin/env python3

def f(s):
    if all([c == 'o' for c in s]):
        return 0
    elif all([c == 'o' for c in s[R:]]):
        return 1
    elif s[0] == '.':
        return f('o' * (R - 1) + s[R:]) + 2
    else:
        return f(s[1:]) + 1

N, R = map(int, input().split())
S = input().strip()
print(f(S))
