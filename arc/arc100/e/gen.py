#!/usr/bin/env python3

import random

def main():
    n = 16
    en = 2 ** n
    axs = [str(random.randrange(1, 10**9)) for i in range(en)]
    print(n)
    print(" ".join(axs))

if __name__ == '__main__':
    main()
