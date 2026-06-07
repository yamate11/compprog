#!/usr/bin/env python3

import time
import sys
from subprocess import PIPE, run

for n in [18, 19, 20, 21, 22]:
    a = []
    b = [0 for _ in range(5)]
    rep = 10
    for t in range(rep):
        instr = f'{n}'
        cp = run(['./foo'], encoding='utf-8', stdout=PIPE, input=instr)
        lst = list(map(float, cp.stdout.split()))
        for i in range(5):
            b[i] += lst[i]
        a.append(lst)
        time.sleep(2)
    print(n)
    print([int(1000 * b[i]) // rep for i in range(5)], flush=True)
    
