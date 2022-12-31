#!/usr/bin/env python3

class A:
    def __init__(self, *args):
        if len(args) == 1 and isinstance(args[0], str):
            print('case 1')
            return
        if len(args) == 2:
            (a1, a2) = args
            if isinstance(a1, int) and isinstance(a2, int):
                print('case 2')
                return
            elif isinstance(a1, str) and isinstance(a2, str):
                print('case 3')
                return
        raise TypeError('Unknown argument type combination')

a = A('foo')
b = A(3, 4)
c = A('foo', 'bar')
d = A()

        
    
