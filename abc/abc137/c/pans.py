#!/usr/bin/env python3

def main():
    N = int(input())
    s = [0 for i in range(N)]
    for i in range(N):
        s[i] = sorted(input())
    s.sort()
    prev = ""
    cnt = -1
    ans = 0
    for i in range(N):
        if (s[i] == prev): cnt += 1
        else:
            if cnt > 1: ans += cnt * (cnt - 1) // 2
            prev = s[i]
            cnt = 1
    if cnt > 1: ans += cnt * (cnt - 1) // 2
    print(ans)

main()
