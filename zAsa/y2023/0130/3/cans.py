#!/usr/bin/env python3

H, W, N = map(int, input().split())
AB = [tuple(map(int, input().split())) for _ in range(N)]
ordA, ordB = [sorted(list(range(N)), key=lambda i: AB[i][j]) for j in range(2)]
for i in range(N):
    print(ordA[i] + 1, ordB[i] + 1)
    

