#!/home/y-tanabe/.venv_10/bin/python

def main():
    N, K = map(int, input().split())
    ans = [0 for _ in range(N + 1)]
    cur = [0 for _ in range(N + 1)]
    cur[0] = 1
    lb = 0
    for k in range(K, int(1e9)):
        if lb + k > N:
            break
        prev = cur
        cur = [0 for _ in range(N + 1)]
        for r in range(k):
            if lb + r >= N + 1:
                break
            s = prev[lb + r]
            for p in range(lb + r + k, N + 1, k):
                cur[p] = s
                s += prev[p]
        for i in range(lb, N + 1):
            ans[i] += cur[i]
        lb += k
    print(' '.join(map(str, ans[1:])))

main()
