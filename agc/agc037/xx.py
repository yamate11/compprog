#!/usr/bin/env python3

a = [9817, 1108, 6890, 4343, 8704];

t = False
while True:
    for i in range(5):
        j = (i-1) % 5
        k = (i+1) % 5
        if a[i] > a[j] + a[k]:
            a[i] -= (a[j] + a[k])
            print(a)
            t = True
            break
    if t == False:
        break
