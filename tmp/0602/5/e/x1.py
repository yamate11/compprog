#!/usr/bin/env python3

import math

primeA = 1000000007;

def main():
    n = int(input())
    x = 1
    for i in range(1, n + 1):
        x *= i
        y = math.gcd(x, primeA)
    print(x & 1)
    

main()
    
