#!/usr/bin/env python3

# 全探索
# 愚直解

def main():

    (N, Y) = map(int, input().split())

    # 三重ループ   N**3 回  N <= 2000 = 2 * 10**3    N**3 == 8 * 10**9
    for x in range(N+1):
        for y in range(N+1):
            # x と y の値は決まっている．
            if x + y > N:
                break
            z = N - (x + y)
            # if 10000 * x + 5000 * y + 1000 * z == Y and x + y + z == N:
            if 10000 * x + 5000 * y + 1000 * z == Y:
                print(f'{x} {y} {z}')
                return
    print('-1 -1 -1')

main()
