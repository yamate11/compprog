#!/usr/bin/env python3

# This is a sample program for testing answer for interactive problems.

import sys, argparse

end_mark = '^__=end=__^'
end_file_mark = '^__=end_file=__^'

def fatal(*msg):
    print("FATAL: ", *msg, file=sys.stderr)
    sys.exit(1)

class JudgeExc(Exception):
    pass

def wa(*msg):
    print("WA", *msg)
    raise JudgeExc

def ac():
    print("AC")
    raise JudgeExc

# An object of class Cans starts ./cans (or what you give in
# a keyword parameter cmd).  Methods pout() and rin() are for I/O from/to
# ./cans.

class Cans:
    def __init__(self, cmd=['./cans']):
        from subprocess import Popen, PIPE
        self.proc = Popen(cmd, encoding='UTF-8', stdin=PIPE, stdout=PIPE)

    def pout(self, *msg):
        print(*msg, flush=True, file=self.proc.stdin)

    def rin(self):
        return self.proc.stdout.readline()

def main():
    ap = argparse.ArgumentParser();
    ap.add_argument('-m', '--multiple', action='store_true',
                    help='runs multiple sessions');
    args = ap.parse_args()
    
    while True:
        try:
            a_session()
        except JudgeExc:
            pass
        if not args.multiple:
            break
        line = input().strip()
        if line == end_file_mark:
            break
        elif line != end_mark:
            fatal("Unexpected input.")

# A sample main() function.  This is for
# Codeforces R.#415(Div.2) - D - Glad to see you!

def a_session():
    n, start, x, ans = map(int, input().strip().split())
    v = []
    nxt = []
    for i in range(n):
        a, b = map(int, input().strip().split())
        v.append(a)
        nxt.append(b)

    cans = Cans()
    cans.pout(n, start, x)
    cnt = 0
    while True:
        cnt += 1
        if cnt > 2000:
            wa("query number exceeds")
        line = cans.rin().strip()
        x, y = line.split()
        if x == "!":
            if int(y) == ans:
                ac()
            else:
                wa(f"expected: {ans}, actual: {y}")
        elif x == "?":
            idx = int(y)
            if idx < 1 or idx > n:
                wa(f"index out of range: {idx}")
            cans.pout(v[idx - 1], nxt[idx - 1])
        else:
            wa(f"Unexpected query format: {line}")

main()
