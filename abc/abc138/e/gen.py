#!/usr/bin/env python

import random
from random import randrange 

slen = 5
tlen = 5

def main():
    s = ''.join(random.choices('abc', k = 3))
    t = ''.join(random.choices('abc', k = 3))
    print(s)
    print(t)

# def main():
#     x = "abcdefghijklmnopqrstuvwxyz"
#     s = ''.join(list(reversed(x))) + ('z' * 10**5)
#     t = x * (10 ** 5 // 26)
#     print(s)
#     print(t)

main()

