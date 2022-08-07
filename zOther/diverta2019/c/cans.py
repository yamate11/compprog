#!/usr/bin/env python3

N = int(input())
ans = 0
c1 = 0
c2 = 0
c3 = 0
for _ in range(N):
    s = input().rstrip()
    for i in range(len(s) - 1):
        if s[i:i+2] == "AB":
            ans += 1
    if s[0] == "B" and s[-1] == "A":
        c1 += 1
    elif s[0] == "B":
        c2 += 1
    elif s[-1] == "A":
        c3 += 1
if c1 > 0:
    ans += c1 - 1  # 1型を全部つなげる
    if c2 > 0:     # 2型があったら，末尾に付ける
        ans += 1
        c2 -= 1
    if c3 > 0:     # 3型があったら，先頭に付ける
        ans += 1
        c3 -= 1
ans += min(c2, c3) # 残った2型と3型をつなげる
print(ans)

