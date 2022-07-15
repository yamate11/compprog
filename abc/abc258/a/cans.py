#!/usr/bin/env python3


def main():
    K = int(input())
    if K <= 59:
        print(f"21:{K:02d}")
    else:
        print(f"22:{K-60:02d}")

main()        
