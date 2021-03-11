#!/usr/bin/env python3

s = input().strip()
v1 = s.split('+')
cnt = 0
for t in v1:
    v2 = t.split('*')
    hasZero = False
    for e in v2:
        if e == '0':
            hasZero = True
            break
    if not hasZero:
        cnt += 1
print(cnt)
