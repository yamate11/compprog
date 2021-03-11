#!/usr/bin/env python3

import re
from datetime import date

def main():
    N = int(input())
    hol = [0] * 366
    for i in range(366):
        if i % 7 == 0 or i % 7 == 6:
            hol[i] = 1
    first = date(2012, 1, 1)
    for i in range(N):
        mo = re.match(r'(\d+)\/(\d+)', input())
        m = int(mo[1])
        d = int(mo[2])
        do = date(2012, m, d)
        ts = do - first
        j = ts.days
        while j < 366 and hol[j] == 1:
            j += 1
        if j < 366:
            hol[j] = 1
    ans = 0
    cons = 0
    for i in range(367):
        if i == 366 or hol[i] == 0:
            ans = max(ans, cons)
            cons = 0
        elif hol[i] == 1:
            cons += 1
    print(ans)

main()
