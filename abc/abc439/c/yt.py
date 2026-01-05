#!/usr/bin/env python3

import sys
import time
from subprocess import run, PIPE, DEVNULL

def main():
    x = int(sys.argv[1])
    repeat = 10
    intv = 2.0
    lst = [0] * repeat
    ans = [0.0] * 4
    for i in range(repeat):
        cp = run(['./foo'], input=f'{x}', encoding='UTF-8', stdout=PIPE, stderr=DEVNULL)
        lst[i] = list(map(float, cp.stdout.split()))
        for j in range(4):
            ans[j] += lst[i][j]
        time.sleep(intv)
    for i in range(4):
        ans[i] /= repeat
    print(ans)

main()
