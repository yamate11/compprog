#!/usr/bin/env python3

def func1():
    def func2():
        nonlocal a
        print(a)
        a = 5
        print(a)
    a = 10
    func2()
    print('after func2', a)

func1()

        
