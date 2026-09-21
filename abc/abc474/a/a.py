#!/usr/bin/env python3


import sys

def debug(*x):
    print(*x, file=sys.stderr)

debug(10, 20, 'abc')
