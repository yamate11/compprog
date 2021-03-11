#!/usr/bin/env python3

import sys

def main():
    pattern = "WBWBWWBWBWBW";
    info = {"Do": 0, "Re": 2, "Mi": 4, "Fa": 5, "So": 7, "La": 9, "Si": 11}
    patFrom = dict()
    for (level, offset) in info.items():
        s = ''
        for i in range(20):
            s += pattern[(offset + i) % len(pattern)]
        patFrom[level] = s
    given = input().strip()
    for k in patFrom:
        if patFrom[k] == given:
            print(k)
            sys.exit(0)

main()
