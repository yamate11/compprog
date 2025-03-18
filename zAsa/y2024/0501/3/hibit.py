#!/usr/bin/env python3

n = int(input())
s = input()
s = list(s)
q = int(input())

shift = 0
for _ in range(q):
    t,a,b = list(map(int, input().split(' ')))
    a -= 1
    b -= 1
    if t == 1:
        s[(a+shift)%(2*n)],s[(b+shift)%(2*n)] = s[((b+shift)%(2*n))], s[(a+shift)%(2*n)]
    if t == 2:
        shift += n


ans = ''.join([s[(i+shift)%(2*n)] for i in range(2*n)])

print(ans)
