#!/usr/bin/env python3

import sys
from subprocess import run, PIPE

def warn(*msg):
    print(*msg, file=sys.stderr)

def main():
    line1 = input().rstrip()
    line2 = input().rstrip()
    act = input().rstrip()
    if act[-1] == '=':
        av = eval(act[:-1])
    else:
        av = int(act)
    if av != int(line2):
        warn(f'av={av}, line2={line2}')
        print('NG')
        return
    cp = run(['./kmjp'], input=f'{line1}\n{line2}\n', encoding='UTF-8',
             stdout=PIPE);
    ref = cp.stdout.rstrip()
    if len(ref) != len(act):
        warn(f'ref={ref}, act={act}')
        print('NG')
    print('OK')

main()
