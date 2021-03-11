def solve(N, T, A, ls_H):
    dosi = []
    titen = []
    titen1 = []
    ti = 100000
    for x in ls_H :
        do = T - x * 0.006
        dosi.append(do)
    #print(dosi)
    
    for y in dosi :
        ti = A - y
        titen.append(ti)
    #print(titen)
    
    for z in titen :
        titen1.append(abs(z))
    #print(titen1)
    
    for i in titen1 :
        if ti > i :
            ti = i
    #print(ti)
    return titen1.index(ti) + 1
 
 
def readQuestion():
    ws = sys.stdin.readline().strip().split()
    N = int(ws[0])
    ws = sys.stdin.readline().strip().split()
    T = int(ws[0])
    A = int(ws[1])
    ws = sys.stdin.readline().strip().split()
    ls_H = list(map(int, ws))
    return (N, T, A, ls_H)
 
def main():
    print(solve(*readQuestion()))
 
# Uncomment before submission
main()

