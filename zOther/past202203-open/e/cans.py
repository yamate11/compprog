#!/usr/bin/env python3

from datetime import date, timedelta


def good(x):
    ss = f'{x.year}{x.month:02d}{x.day:02d}'
    v = [0 for _ in range(10)]
    for c in ss:
        v[int(c)] = 1;
    nn = sum(v)
    if nn <= 2:
        return True
    else:
        return False

S = input()
y = int(S[0:4])
m = int(S[5:7])
d = int(S[8:10])
x = date(y, m, d)
# print(x)
while True:
    if good(x):
        print(f'{x.year}/{x.month:02d}/{x.day:02d}')
        break
    x += timedelta(days=1)

