#!/usr/bin/env python3

from subprocess import Popen, PIPE
import re

def func(size):
    eff = False
    val = 0
    with Popen(['./foo', str(size)], encoding='UTF-8',
               stdin=PIPE, stdout=PIPE) as proc:
        ack = proc.stdout.readline()
        with open(f'/proc/{proc.pid}/smaps') as fp:
            for line in fp:
                line = line.rstrip()
                mo = re.match(r'\w+\-\w+ .... \w+ \d\d\:\d\d \d+\s*(.*)', line)
                if mo:
                    if mo[1] == '[heap]':
                        eff = True
                    elif mo[1] == '':
                        pass
                    else:
                        eff = False
                mo = re.match(r'Rss:\s*(\d+)', line)
                if eff and mo:
                    val += int(mo[1])
        print(0, file=proc.stdin, flush=True)
    return val

def main():
    for size in range(0, 41):
        print(f'{size},{func(size)}')

main()
