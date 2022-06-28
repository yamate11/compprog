#!/usr/bin/env python3

import sys, time

def main():
    print('Python String Results')
    print(f'version: {sys.version}')
    for pow in [20, 22, 24, 26]:
        loop = 1<<pow
        s1 = ''
        s2 = ''
        t1 = time.time()
        for i in range(loop):
            s1 += 'a'          # (A)
        t2 = time.time()
        for i in range(loop):
            s2 = s2 + 'a'      # (B)
        t3 = time.time()
        print(f'2**{pow}')
        print(f'   (A): {t2 - t1}')
        print(f'   (B): {t3 - t2}')

main()
