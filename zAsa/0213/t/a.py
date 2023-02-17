#!/usr/bin/env python3

vec = [[] for i in range(100)]

def show(v):
    for i in range(len(v)):
        print(f'{v[i] - i:2d}', end=' ')
    print()

def show2(v):
    for x in v:
        if x is None:
            print('**', end=' ')
        else:
            print(f'{x:2d}', end=' ')
    print()

def f(n):
    if n == 2:
        vec[2] = [1, 0]
    else:
        a = vec[n - 1] + [n - 1]
        b = [0 for i in range(n)]
        b[0] = a[0]
        for i in range(n - 1):
            b[1 + i] = a[1 + vec[n - 1][i]]
        vec[n] = b
    print(f'{n:2d}:', end=' ');
    show(vec[n])
    # c = []
    # for i in range(n):
    #     find = False
    #     for j in range(n - 1):
    #         if vec[n][i] == vec[n - 1][j]:
    #             c.append(j - i)
    #             find = True
    #             break
    #     if not find:
    #         c.append(None)
    # print(f'{n:2d}:', end=' ');
    # show2(c)

def main():
    vec[0] = []
    vec[1] = [0]
    for i in range(2, 100):
        f(i)

main()
