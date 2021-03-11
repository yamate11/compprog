import sys
a, b, c = map(int, sys.stdin.readline().split(' '))
k = int(sys.stdin.readline())
x = max(a, b, c)
print(x * (2 ** k) + a + b + c - x)


