import sys
 
def solve(N, T, A, ls_H):
    for i in range(N):
        val = abs(A - (T - ls_H[i] * 0.006))
        print(val)
        if i == 0:
            minVal = val
            minIdx = 0
        elif minVal > val:
            minVal = val
            minIdx = i
        print(minVal, minIdx)
    return minIdx + 1
 
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
