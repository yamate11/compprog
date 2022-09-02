#!/usr/bin/env python3

def chmax(a, b):
    if (a < b):
        a = b
        return True
    else:
        return False

S = input().rsplit()
N = len(S) + 1
A = [0] * N
for i in range(N - 1):
    chmax(A[i + 1], A[i] + 1)
for i in range(N - 2, -1, -1):
    chmax(A[i], A[i + 1] + 1)
print(sum(A))

