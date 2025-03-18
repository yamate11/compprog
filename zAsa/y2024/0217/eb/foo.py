#!/usr/bin/env python3

import time



for _ in range(10):

    # 1000 x 1000 の二重ループ
    start_time = time.time()
    a = [[0 for _x in range(1024)] for _y in range(1024)]
    s = 0
    for i in range(1024):
        for j in range(1024):
            a[i][j] = i * j
    double_loop_time = time.time() - start_time

    # 1000000 の一重ループ
    start_time = time.time()
    b = [0] * (1<<20)
    for i in range(1<<20):
        b[i] = (i >> 10) * (i & 0x3FF)
    single_loop_time = time.time() - start_time

    print(f'double:{double_loop_time:.3f}, single:{single_loop_time:.3f}')
    
