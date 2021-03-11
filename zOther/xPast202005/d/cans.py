#!/usr/bin/env python3

import sys

spec='''.###..#..###.###.#.#.###.###.###.###.###.
.#.#.##....#...#.#.#.#...#.....#.#.#.#.#.
.#.#..#..###.###.###.###.###...#.###.###.
.#.#..#..#.....#...#...#.#.#...#.#.#...#.
.###.###.###.###...#.###.###...#.###.###.'''

def debug(msg):
    print(msg, file=sys.stderr)

def main():
    tt = spec.split()
    ss = [['' for a in range(5)] for b in range(10)]
    # print(tt)
    for r in range(5):
        for i in range(10):
            s = 4*i + 1
            e = 4*(i + 1)
            ss[i][r] = tt[r][s:e]

    N = int(input())
    qq = []
    for i in range(5):
        qq.append(input().strip())

    def myread(x):
        debug("myread " + str(x))
        for n in range(10):
            match = True
            for r in range(5):
                debug(f"n = {n}, r= {r}, ss[n][r] = {ss[n][r]}, qq[r][...] = {qq[r][4*x + 1 : 4*(x+1)]}")
                if ss[n][r] != qq[r][4*x + 1 : 4*(x+1)]:
                    match = False
                    break
            if match:
                return n
        print("ERROR\n");
        sys.exit(1)

    for i in range(N):
        print(myread(i), end='')
    print()


main()
