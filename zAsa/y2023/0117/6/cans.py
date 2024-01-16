#!/usr/bin/env python3

x, y = map(int, input().split('/'))
t = 2 * x // y - 1;
cands = [t + 1, t + 2]
ans = []
for n in cands:
    if x * n % y != 0:
        continue
    m = n * (n + 1) // 2 - x * n // y
    if 1 <= m and m <= n:
        ans.append((n, m))
if len(ans) == 0:
    print('Impossible')
else:
    ans.sort()
    for (n, m) in ans:
        print(n, m)
