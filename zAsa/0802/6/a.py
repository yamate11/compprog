#!/usr/bin/env python3

class MyClass:
    var = 1
    def m1(self):
        print(self.var)

a = MyClass()
b = MyClass()

MyClass.var = 4
a.var = 2

def func(x):
    print(x.var)

func(a)
func(b)
a.m1()
b.m1()



