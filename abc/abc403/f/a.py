#!/usr/bin/env python3

from subprocess import run, PIPE

def main():
    for x in range(1, 2001):
        cp1 = run(['./cans'], input=str(x), encoding='UTF-8', stdout=PIPE)
        cp2 = run(['./cans2'], input=str(x), encoding='UTF-8', stdout=PIPE)
        if len(cp1.stdout) != len(cp2.stdout):
            print(x)
            return

main()

