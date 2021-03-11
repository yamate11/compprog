#!/usr/bin/env python3

import sys

def warn(*msg):
    print(*msg, file=sys.stderr)

def find_period(v, k, lim_period, start, conf):
    for period in range(1, lim_period + 1):
        lim = start + period * (conf + k)
        if len(v) < start + lim:
            warn(f'find_period: v is not long enough for ({period}, {k}).')
            return (None, None)
        w = v[ start : start + lim ]
        for k1 in range(k+1):
            def achieve_const():
                for j in range(period):
                    for l in range(conf - 1):
                        if w[j + period * l] != w[j + period * (l+1)]:
                            return False
                return True
            if achieve_const():
                return (k1, period)
            if k1 == k:
                break
            for t in range(period * (conf + (k - k1 - 1))):
                w[t] = w[t + period] - w[t]
    return (None, None)
        
def main():
    n = 1000
    vec = [0] * n

    # a-1, a, b; a+2 <= b
    for a in range(2, n):
        for b in range(a + 2, n):
            if a-1 + a > b:
                l = a-1 + a + b
                if l < n:
                    vec[l] += 1

    # b, a-1, a;  b <= a-3
    for a in range(2, n):
        for b in range(2, a-3):
            l = a-1 + a + b
            if l < n:
                vec[l] += 1

    # a-1, a, a+1
    for a in range(3, n):
        l = 3 * a
        if l < n:
            vec[l] += 1

    f = [0] * n
    sum = 0
    for x in range(n):
        sum += vec[x]
        f[x] = sum

    (k, period) = find_period(f, 2, 20, 100, 10)
    if period is None:
        print("Not found")
        sys.exit(1)

    print(f'dim = {k}, period = {period}')



main()
