#!/usr/bin/env python3


N = int(input())
H = list(map(int, input().strip().split()))  # H[0] .. H[N-1]

def func(l, r):   # l以上r未満の範囲について考える
    hmin = 1000
    for i in range(l, r):
        if H[i] < hmin:
            hmin = H[i]
    lst = [l-1]
    for i in range(l, r):
        if H[i] == hmin:
            lst.append(i)
    lst.append(r)

    # lst[0] + 1 = l 以上 lst[0] 未満          .. .まだ数えなくてはいけない
    # lst[0] + 1 以上 lst[1] 未満 .. .まだ数えなくてはいけない
    # lst[1] + 1 以上 lst[2] 未満 .. .まだ数えなくてはいけない
    # ....
    # lst[k-2] + 1以上 r = lst[k-1] 未満      .. .まだ数えなくてはいけない

    for i in range(l, r):
        H[i] -= hmin

    ans = hmin
    for i in range(len(lst) - 1):
        # ans += lst[i] + 1 以上 lst[i-1] 未満の水やりの数
        ans += func(lst[i] + 1, lst[i-1])   # 再帰呼び出し
    return ans

print(func(0, N))


