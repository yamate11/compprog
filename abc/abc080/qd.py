#!/usr/bin/python3

import sys

def main():
    n, c = getLineInts()
    ss = [0 for i in range(n)]
    ts = [0 for i in range(n)]
    cs = [0 for i in range(n)]
    ics = [[] for c in range(31)]
    for i in range(n):
        ss[i], ts[i], cs[i] = getLineInts()
        ics[cs[i]].append(i)
        
    icms = []
    for c in range(31):
        prepS = None
        prepT = None
        for i in sorted(ics[c], key = lambda i: ss[i]):
            if prepS is not None and prepT == ss[i]:
                prepT = ts[i]
            else:
                if prepS is not None:
                    icms.append((prepS, 0))
                    icms.append((prepT, 1))
                prepS = ss[i]
                prepT = ts[i]
        if prepS is not None:
            icms.append((prepS, 0))
            icms.append((prepT, 1))
    
    vMax = 0
    cur = 0
    icms = sorted(icms, key = lambda e: e[1])
    icms = sorted(icms, key = lambda e: e[0])
    for (t, type) in icms:
        if type == 0:
            cur += 1
            if vMax < cur:
                vMax = cur
        else:
            cur -= 1
    print(vMax)


def getLineInts():
    return [int(x) for x in sys.stdin.readline().rstrip().split(' ')]


if __name__ == '__main__':
    main()


    
