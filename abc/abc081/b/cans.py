#!/usr/bin/env python3

N = int(input())
lstA = []
line = input()
for s in line.split():
    lstA.append(int(s))

cnt = 0
success = True
while success:
    lstB = []
    for x in lstA:
        if x % 2 == 0:
            lstB.append(x // 2)
        else:
            success = False
            break
    if success:
        lstA = lstB
        cnt += 1
print(cnt)
