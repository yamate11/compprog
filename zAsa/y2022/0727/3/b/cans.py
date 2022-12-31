#!/usr/bin/env python3
from datetime import date, timedelta

s = input().rstrip()
y0 = int(s[0:4])
m0 = int(s[5:7])
d0 = int(s[8:10])

cur = date(y0, m0, d0)
while True:
    y = cur.year
    m = cur.month
    d = cur.day
    if y % (m * d) == 0:
        print(f'{y:04d}/{m:02d}/{d:02d}')
        break
    cur += timedelta(days=1)
    
