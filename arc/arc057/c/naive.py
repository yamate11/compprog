#!/usr/bin/env python3

import math

def main():
    goal = input().strip()
    n = len(goal)
    for i in range(1,int(1e10)):
        s = math.sqrt(i)
        if goal == (str(s).replace('.', '') + ('0' * n))[:n]:
            print(i)
            return

main()
