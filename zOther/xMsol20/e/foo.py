#!/usr/bin/env python3

def fact():
    f = 1
    for i in range(1, 33):
        f *= i
        print(f'{i:2d} {f:.1e} {f:36}')

def combi():
    N = 65
    c = [[0 for j in range(i+1)] for i in range(N)]
    for i in range(1, N):
        c[i][0] = 1
        c[i][i] = 1
        for j in range(1, i):
            c[i][j] = c[i-1][j-1] + c[i-1][j]
            
    for i in range(1, 17):
        print(f'{i:2d}', " ".join([f'{c[i][j]:5d}' for j in range(i+1)]))

    for i in range(1, N):
        print(f'2 ** {i:2d} = {2**i:.2e}, ', 
              f'C({i:2d}, {i//2:2d}) = {c[i][i//2]:.2e}')

fact()

