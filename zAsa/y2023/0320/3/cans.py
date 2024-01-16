#!/usr/bin/env python3

import sys
from datetime import date, timedelta

S = input().strip()
y = int(S[0:4])
m = int(S[5:7])
d = int(S[8:10])

dd = date(y, m, d)
while True:
    if dd.year % (dd.month * dd.day) == 0:
        print(f'{dd.year:04d}/{dd.month:02d}/{dd.day:02d}')
        sys.exit(0)
    dd += timedelta(days=1)
