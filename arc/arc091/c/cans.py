#!/usr/bin/env python3

def main():
    (N, M) = map(int, input().split())
    if N >= M:
        (N, M) = (M, N)
    if N == 1:
        if M == 1:
            print(1)
        else:
            print(M-2)
    else:
        print((N-2) * (M-2))
    

main()
