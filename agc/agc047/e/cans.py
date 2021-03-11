#!/usr/bin/env python3

LT = '<'
ADD = '+'

mc = 3
ops = []

zero = None
one = None
tp_size = 31
twopow = None

def getM():
    global mc
    mc += 1
    return mc - 1

def setOp(opc, i, j, k):
    ops.append(f'{opc} {i} {j} {k}')
    
def mylog(msg, *vs):
    ops.append(f"D '{msg}' " + ' '.join(map(str, vs)))

def assign(i, j):  # vec[i] <- vec[j]
    setOp(ADD, zero, j, i)

def add(i, j):
    m = getM()
    setOp(ADD, i, j, m)
    return m

def lt(i, j):
    m = getM()
    setOp(LT, i, j, m)
    return m

def le(i, j):  # vec[i] <= vec[j]
    m = lt(i, add(j, one))
    return m

def myor(i, j):
    return lt(zero, add(i, j))

def mynot(i):
    return lt(i, one)

def myand(i, j):
    m = mynot(myor(mynot(i), mynot(j)))
    # mylog('and', i, j, m);
    return m

# returns [vec[x], 2vec[x], 4vec[x], 8vec[x], ...]
def mktwopow(x):
    ret = []
    ret.append(x)
    last = x
    for k in range(1, tp_size):
        last = add(last, last)
        ret.append(last)
    return ret

def myifk(f, k): # if f > 0 then 2^k else 0
    if k == 0:
        return lt(zero, f)
    else:
        m = myifk(f, k-1)
        return add(m, m)

def myif(f, x): # if f > 0 then x else 0
    t = zero
    for k in range(tp_size - 1, -1, -1):
        s = myifk(myand(f, le(add(t, twopow[k]), x)), k)
        t = add(t, s)
    return t

def prod(x, y):
    t = zero
    s = zero
    for k in range(tp_size - 1, -1, -1):
        # mylog(f'k={k}', twopow[k])
        tc = add(t, twopow[k])
        f = le(tc, x)
        yf = myif(f, y)
        for i in range(k):
            yf = add(yf, yf)
        s = add(s, yf)
        t = add(t, myif(f, twopow[k]))
        # mylog('s', s)
        # mylog('t', t)
    return s
        
def pout():
    print(len(ops))
    for s in ops:
        print(s)                

def main():
    global ops, mc, zero, one, twopow
    ops = []
    zero = getM()
    one = lt(zero, add(lt(zero, 0), lt(zero, 1)))
    twopow = mktwopow(one)
    assign(2, prod(0, 1))
    pout()

main()
