#!/usr/bin/python3

import time
from subprocess import run, DEVNULL

def singleMeasure(mode):
    with open('data1.txt', 'r') as f:
        t1 = time.time()
        run(["./p1", str(mode)], stdin = f, stdout = DEVNULL)
        t2 = time.time()
        return t2 - t1

def multMeasure(num, mode):
    singleMeasure(mode)
    sum = 0
    for i in range(num):
        sum += singleMeasure(mode)
    return (sum / num)

def myMeasure(mode):
    num = 3
    result = multMeasure(num, mode)
    print(mode, result)

def main():
    myMeasure(1)
    myMeasure(2)
    myMeasure(3)
    myMeasure(4)


if __name__ == '__main__':
    main()
