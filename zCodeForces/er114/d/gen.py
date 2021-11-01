from random import randrange

n = 10
m = 5
lim = 5
lim2 = 100
print(n)
for i in range(n):
    c = randrange(1, lim)
    
    print(c, end=' ')
    s = set()
    for j in range(c):
        while True:
            x = randrange(1, lim2)
            if x not in s:
                break
        s.add(x)
    for x in s:
        print(x, end=' ')
