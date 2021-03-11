#!/usr/bin/env python3

import random, subprocess, sys

tfile = 'dt.txt'

def answer(cmd):
    with open(tfile) as fp:
        cp = subprocess.run([cmd], encoding='utf-8',
                            stdin=fp, stdout=subprocess.PIPE)
        if cp.returncode != 0:
            print(f'{cmd} failed.', file=sys.stderr)
            sys.exit(1)
        return int(cp.stdout.strip())

def main():
    c = 1000
    for i0 in range(c):
        print(i0, end=' ', flush=True)
        for i1 in range(i0,c,271):
            for i2 in range(i1,c,391):
                with open(tfile, 'w', encoding='utf-8') as wfp:
                    print(3, file=wfp)
                    print(i0, i1, i2, file=wfp)
                x = answer('./ans')
                y = answer('./simp')
                if x != y:
                    print(f'ans = {x} ... simp = {y}')
                    sys.exit(1)

main()
