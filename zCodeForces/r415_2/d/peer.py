#!/usr/bin/env python3

class Cans:
    def __init__(self, cmd=['./cans']):
        from subprocess import Popen, PIPE
        self.proc = Popen(cmd, encoding='UTF-8', stdin=PIPE, stdout=PIPE)

    def pout(self, *msg):
        print(*msg, flush=True, file=self.proc.stdin)

    def rin(self):
        return self.proc.stdout.readline()

def main():
    n = int(input())
    vec = [False] * (n + 1)
    ks = list(map(int, input().strip().split(' ')))
    for k in ks:
        vec[k] = True

    def cnt(t):
        if vec[t]:
            return 0
        i = 1
        while True:
            if t + i <= n and vec[t + i]:
                return i
            if t - i >= 0 and vec[t - i]:
                return i
            i += 1
        

    cans = Cans()
    cans.pout(n, len(ks))
    while True:
        (tp, x, y) = map(int, cans.rin().strip().split(' '))
        if tp == 2:
            if vec[x] and vec[y]:
                print('AC')
            else:
                print(f'WA -- (x,y) = ({x}, {y})')
            break
        if tp == 1:
            p = cnt(x)
            q = cnt(y)
            msg = 'TAK' if p <= q else 'NIE'
            cans.pout(msg)
        else:
            print('WA -- illegal type')
            

main()
