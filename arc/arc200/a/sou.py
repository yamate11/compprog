for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    k = -1
    for i in range(1, n):
        if a[i] * b[0] != b[i] * a[0]:
            k = i
            break
    if k == -1:
        print("No")
        continue
    x = [0] * n
    x[0] = a[i] + b[i]
    x[i] = a[0] + b[0]
    if a[0] * b[i] > a[i] * b[0]:
        x[i] *= -1
    else:
        x[0] *= -1
    print("Yes")
    print(*x)
