#!/usr/bin/python3

import random

def main():
    tMax = 100000
    all = []
    n = 100000 // 30
    for c in range(30):
        t = 1
        for i in range(n):
            rem = tMax - t
            if rem == 0: break
            expLen = (rem + (n - i)) // (n - i)
            thisLen = int(random.random() * expLen)
            gap = int(random.random() * (expLen - thisLen))
            all.append((t + gap, t + gap + thisLen + 1, c))
            t = t + gap + thisLen + 1
    num = len(all)
    random.shuffle(all)
    with open('inData2.txt', 'w') as f:
        print(num, 30, file=f)
        for (s,e,c) in all:
            print(s, e, 1+c, file=f)


if __name__ == '__main__':
    main()
