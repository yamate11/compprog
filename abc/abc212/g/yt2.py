#!/usr/bin/env python3

import sys
from subprocess import run, PIPE

def main():
    with open('primes2.txt') as fp:
        for line in fp:
            p = line.strip()
            cp = run(['./cans'], input=p, encoding='UTF-8',
                     stdout=PIPE)
            ans1 = int(cp.stdout)
            cp = run(['./tat'], input=p, encoding='UTF-8',
                     stdout=PIPE)
            ans2 = int(cp.stdout)
            if ans1 != ans2:
                print(p)

main()
