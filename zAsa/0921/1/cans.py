#!/usr/bin/env python3

from datetime import date, timedelta

def f(m):
    return (date(year=2023, month=(m % 12 + 1), day=1) - timedelta(days=1)).day

x, y = map(int, input().split())
print("Yes" if f(x) == f(y) else "No")
