#!/usr/bin/env python3

def p0(x,y): return x + y + 80
def p1(x,y): return 2*x + y + 60
def p2(x,y): return x + 2*y + 70
def p3(x,y): return 2*x + 2*y + 55
def p4(x,y): return 4*x + 5*y + 2

def q0(x,y): return 2*x + 2*y + 55
def q1(x,y): return 2*x + 1*y + 60
def q2(x,y): return 2*x + 0*y + 70
def q3(x,y): return 0*x + 2*y + 75
def q4(x,y): return 0*x + 1*y + 80
def q5(x,y): return 0*x + 0*y + 90

flst = [p0, p1, p2, p3, p4]
# flst = [q0,q1,q2,q3,q4,q5]

def val(x,y):
    return min([f(x,y) for f in flst])

a = 10
b = 10
print(a, b)
for x in range(1,a+1):
    print(' '.join([str(val(x,y)) for y in range(1,b+1)]))
        
