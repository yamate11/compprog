#!/usr/bin/env python3

if 0:
    a = "SUN,MON,TUE,WED,THU,FRI,SAT".split(',')
    d = {a[i]: i for i in range(7)}
    S = input().rstrip()
    x = d[S]
    if x == 0:
        ans = 7
    else:
        ans = 7 - x
    print(ans)


print(7 - {"SUN,MON,TUE,WED,THU,FRI,SAT".split(',')[i]: i for i in range(7)}[input()])

