#!/usr/bin/env python3

def fact(n):
    if n == 0:
        return 1
    else:
        return n * fact(n-1)
    

def comb(n,r):
    return fact(n) / (fact(r) * fact(n-r))

def main():
    n0 = 16
    s = 0
    for i in range(n0+1):
        s += comb(n0, i) * (2 ** i)
    print(s)
    
main()
