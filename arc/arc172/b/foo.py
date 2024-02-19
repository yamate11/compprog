def fact(n):
    if n == 0:
        return 1
    else:
        return n * fact(n - 1)

def pow(a, b):
    if b == 0:
        return 1
    else:
        return b * pow(a, b - 1)

print(fact(26)/fact(5)*pow(6, 79))

