#!/usr/bin/env python3

# This code was generated by ChatGPT 4.

def solve_case(N, A):
    if N == 1:  # ただ一つの要素がある場合はその要素は常にLISに含まれる
        return f"1\n1"

    # 前から計算したときのLIS長
    lis_forward = [1] * N
    # 後ろから計算したときのLIS長
    lis_backward = [1] * N

    # LISを計算するための値とそのインデックスを保持するリスト
    from bisect import bisect_left

    # 前方向からのLIS
    dp = []
    for i in range(N):
        pos = bisect_left(dp, A[i])
        if pos < len(dp):
            dp[pos] = A[i]
        else:
            dp.append(A[i])
        lis_forward[i] = pos + 1

    # 後方向からのLIS
    dp = []
    for i in range(N-1, -1, -1):
        pos = bisect_left(dp, A[i])
        if pos < len(dp):
            dp[pos] = A[i]
        else:
            dp.append(A[i])
        lis_backward[i] = pos + 1

    max_lis_length = max(lis_forward)

    result_indices = []
    # 各要素について、前方向と後方向のLISの和が全体のLIS長+1になるか確認
    for i in range(N):
        if lis_forward[i] + lis_backward[i] - 1 == max_lis_length:
            result_indices.append(i + 1)

    return f"{len(result_indices)}\n{' '.join(map(str, result_indices))}"

import sys
input = sys.stdin.read
data = input().split()

index = 0
T = int(data[index])
index += 1
results = []
for _ in range(T):
    N = int(data[index])
    index += 1
    A = list(map(int, data[index:index + N]))
    index += N
    result = solve_case(N, A)
    results.append(result)

print("\n".join(results))
