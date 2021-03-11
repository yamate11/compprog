#!/usr/bin/env python3

def main():
    (N, Y) = map(int, input().rstrip().split())
    for x in range(0, N+1):
        for y in range(0, N - x + 1):
            z = N - x - y
            if 10000 * x + 5000 * y + 1000 * z == Y:
                print(x, y, z)
                return
    print(-1, -1, -1)
    

main()
