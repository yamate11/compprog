#!/usr/bin/env python3

y = 80

def main():
    #for yy in range(1, 40):
    for x in range(2, y, 2):
        #y = yy * 2
        for ii in range(0, x * y):
            i = y - ii
            if i % x == y % i:
                print(x,y, i)
                break
    
main()
