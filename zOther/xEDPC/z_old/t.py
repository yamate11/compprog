#!/usr/bin/env python3

import random
import subprocess
import sys

tfile = 'dt.txt'

def answer(cmd):
    with open(tfile) as fp:
        cp = subprocess.run([cmd], encoding='utf-8',
                            stdin=fp, stdout=subprocess.PIPE)
        if cp.returncode != 0:
            print(f'{cmd} failed.', file=sys.stderr)
            sys.exit(1)
        return int(cp.stdout.strip())

def genfile(n,c,var):
    lst = [1]
    x = 1
    for i in range(2,n+1):
        y = random.randrange(1,var)
        x += y
        lst.append(x)
    with open(tfile, "w") as wfp:
        print(n, c, file=wfp)
        print(" ".join(map(str, lst)), file=wfp)

def main():
    for k in range(200):
        genfile(30,10000,1000)
        x = answer('./ans')
        y = answer('./simp')
        if x != y:
            print(f'{x} ... {y}')
            sys.exit(1)
    

main()
