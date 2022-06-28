#!/usr/bin/env python3

import sys, time

def main():
    print(f'version: {sys.version}')
    for pow in [12, 14, 16, 18]:
        loop = 1<<16
        s1 = 'a' * (1<<pow)
        s2 = s1
        s3 = s1
        t1 = time.time()
        for i in range(loop):
            s1 += 'a'          # (A)
        t2 = time.time()
        for i in range(loop):
            s2 = s2 + 'a'      # (B)
        t3 = time.time()
        for i in range(loop):
            tmp = s3 + 'a'     # (C)
            s3 = tmp           # (C)
        t4 = time.time()
        print(f'2**{pow}')
        print(f'   (A): {t2 - t1}')
        print(f'   (B): {t3 - t2}')
        print(f'   (C): {t4 - t3}')

main()
