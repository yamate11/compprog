#!/usr/bin/env python3

from random import randrange

def main():
    N = int(2e5)
    print(N)
    for i in range(2,N+1):
        j = randrange(1,i)
        print(j, i)


main()
