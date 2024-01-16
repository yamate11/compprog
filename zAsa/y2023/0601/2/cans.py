#!/usr/bin/env python3

N = int(input())
line = input().strip()
line = line[:-1]
ws = line.split()
cnt = 0
ok = ['TAKAHASHIKUN', 'Takahashikun', 'takahashikun']
for w in ws:
    if w in ok:
        cnt += 1
print(cnt)
