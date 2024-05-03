#!/usr/bin/env python

def main():
    for n in range(1, 15):
        print(f'n = {n}')
        for m in range(1, 15):
            print(f'm = {m:2d}: ', end=' ')
            for k in range(1, m):
                x = 2**n % (2**m - 2**k)
                print(f'{x:4d}', end=' ')
            print()

main()
