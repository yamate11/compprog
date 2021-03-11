inf = float("inf")
N = int(input())
if N==1:
    print(0)
    exit()
lr = inf
ll = inf
rr = -inf
rl = -inf
ud = -inf
uu = -inf
dd = inf
du = inf
l_stop = inf
r_stop = -inf
u_stop = -inf
d_stop = inf
for _ in range(N):
    x, y, d = input().split()
    x, y = int(x), int(y)
    if d=="R":
        lr = min(lr, x)
        rr = max(rr, x)
    elif d=="L":
        rl = max(rl, x)
        ll = min(ll, x)
    elif d=="U":
        du = min(du, y)
        uu = max(uu, y)
    else:
        ud = max(ud, y)
        dd = min(dd, y)
    if d=="R" or d=="L":
        u_stop = max(u_stop, y)
        d_stop = min(d_stop, y)
    else:
        l_stop = min(l_stop, x)
        r_stop = max(r_stop, x)


def f(t):
    r = max(r_stop, rr+t, rl-t)
    l = min(l_stop, ll-t, lr+t)
    u = max(u_stop, uu+t, ud-t)
    d = min(d_stop, dd-t, du+t)
    return (r-l) * (u-d)
#print(f(1))

high = 10**8
high = float(high)
low = 0.0
while high - low > 0.000001:
    #print(high, low)
    mid_left = high/3+low*2/3
    mid_right = high*2/3+low/3
    if f(mid_left) >= f(mid_right):
        low = mid_left
    else:
        high = mid_right
print(f(round(high, 3)))
