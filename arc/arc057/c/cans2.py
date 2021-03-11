#!/usr/bin/env python3

def solve1():
    lo = int(input().strip())
    hi = lo + 1
    lo2 = str(lo * lo)
    hi2 = str(hi * hi)
    if len(lo2) < len(hi2):
        lo2 = '0' + lo2
    if len(lo2) % 2 == 1:
        lo2 = '0' + lo2
        hi2 = '0' + hi2
    for i in range(0, len(lo2), 2):
        diff = int(hi2[i:i+2]) - int(lo2[i:i+2])
        if diff > 0: break
    if diff == 1 and all([c == '0' for c in hi2[i+2:]]):
        if i == len(lo2) - 2:
            return lo2
        else:
            i += 2
            while lo2[i:i+2] == '99':
                i += 2
    if all([c == '0' for c in lo2[i+2:]]):
        return lo2
    else:
        return lo2[:i] + '{:02d}'.format(1 + int(lo2[i:i+2]))

def solve():
    s = solve1().lstrip('0')
    while s[-2:] == '00':
        s = s[:-2]
    return s

def main():
    print(solve())

main()
