#!/usr/bin/env python3

n = 5000
br = 5000

def mainloop():
    pid = 1
    id = 2
    while True:
        for j in range(br):
            print(pid,id)
            id += 1
            if id > n:
                return
        pid += 1

print(n)
mainloop()

