#!/usr/bin/env python3


N = int(input())
H = list(map(int, input().strip().split()))  # H[0] .. H[N-1]

def func(l, r):   # l�ʾ�r̤�����ϰϤˤĤ��ƹͤ���
    hmin = 1000
    for i in range(l, r):
        if H[i] < hmin:
            hmin = H[i]
    lst = [l-1]
    for i in range(l, r):
        if H[i] == hmin:
            lst.append(i)
    lst.append(r)

    # lst[0] + 1 = l �ʾ� lst[0] ̤��          .. .�ޤ������ʤ��ƤϤ����ʤ�
    # lst[0] + 1 �ʾ� lst[1] ̤�� .. .�ޤ������ʤ��ƤϤ����ʤ�
    # lst[1] + 1 �ʾ� lst[2] ̤�� .. .�ޤ������ʤ��ƤϤ����ʤ�
    # ....
    # lst[k-2] + 1�ʾ� r = lst[k-1] ̤��      .. .�ޤ������ʤ��ƤϤ����ʤ�

    for i in range(l, r):
        H[i] -= hmin

    ans = hmin
    for i in range(len(lst) - 1):
        # ans += lst[i] + 1 �ʾ� lst[i-1] ̤���ο���ο�
        ans += func(lst[i] + 1, lst[i-1])   # �Ƶ��ƤӽФ�
    return ans

print(func(0, N))


