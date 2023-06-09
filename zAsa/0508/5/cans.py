#!/usr/bin/env python3

N = int(input())
sz = 60 // 5 * 24
rec = [False for _ in range(sz + 2)]
for _ in range(N):
    line=input()
    a = (int(line[0:2]) * 60 + int(line[2:4])) // 5
    b = (int(line[5:7]) * 60 + int(line[7:9]) + 4) // 5
    for t in range(a, b):
        rec[1 + t] = True
for i in range(sz + 1):
    (a, b) = divmod(i * 5, 60)
    if not rec[i] and rec[i + 1]:
        print(f'{a:02d}{b:02d}', end='-')
    if rec[i] and not rec[i + 1]:
        print(f'{a:02d}{b:02d}')
