import sys
a, b = map(int, sys.stdin.readline().split(' '))
print(a if a <= b else a - 1)
