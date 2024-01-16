#!/usr/bin/env python3

import sys

def debug(*msg):
    print(*msg, file=sys.stderr)

ss = input().rstrip().split()
N = int(input())
ts = [input().rstrip() for i in range(N)]
ans = []
debug(ss)
debug(ts)
for s in ss:
    def matchok():
        for t in ts:
            def ok():
                if len(s) != len(t):
                    return False
                for (a, b) in zip(s, t):
                    if b == '*' or a == b:
                        continue
                    return False
                return True
            if ok():
                return True
        return False
    if matchok():
        ans.append('*' * len(s))
    else:
        ans.append(s)

print(' '.join(ans))

            
