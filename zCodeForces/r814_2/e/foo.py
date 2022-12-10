#!/usr/bin/env python3

fib = [1, 1]
idx = 2
while True:
    t = fib[idx - 1] + fib[idx - 2]
    if t > 10**9:
        break
    fib.append(t)
    idx += 1
print(fib)
print(len(fib))
