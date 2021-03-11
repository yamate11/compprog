#!/usr/bin/env python3

import random

vec = [9923, 9885, 9828, 9741, 9609, 9406, 9090, 8589, 7769, 6321]

def main():
    lst = list(range(1, 10001))
    random.shuffle(lst)
    top = 1000000
    k = 0
    for i in range(10000):
        x = lst[i]
        if x >= top: continue
        if k < 10 and 10000 - i < vec[k]:
            print(f"+ {x:4d} {i+1:4d}")
            k += 1
        else:
            print(f"- {x:4d} {i+1:4d}")
        top = x

main()
