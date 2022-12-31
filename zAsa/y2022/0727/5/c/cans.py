def solve():
    N = int(input())
    A = list(map(int, input().split()))
    if N == 0:
        return 1 if A[0] == 1 else -1
    if A[0] > 0:
        return -1
    L = [0] * (N + 1)
    for i in range(N - 1, -1, -1):
        L[i] = L[i + 1] + A[i]
    V = [1]
    for i in range(1, N + 1):
        v = min(L[i], 2 * (V[i - 1] - A[V - 1]))
        if v < A[i]:
            return -1
        V.append(v)
    return sum(V)
