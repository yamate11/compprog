import sys
 
def solve(N, T, A, ls_H):
    return min([(abs(A - (T - h * 0.006)), i) for (i, h) in enumerate(ls_H, start=1)])[1]
 
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
