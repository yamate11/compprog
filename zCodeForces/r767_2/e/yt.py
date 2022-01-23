#!/usr/bin/env python3

def show(i, brd):
    # print(i)
    for (j, row) in enumerate(brd):
        if j == i:
            print(''.join(map(str, row)))
        # if j == i or j == i + 1:
        #     print(''.join(map(str, row)))


def main():
    n = 12
    board = [[0 for _ in range(n)] for __ in range(n)]
    for i in range(1, n):
        for j in range(n):
            if board[i - 1][j] == 0:
                for (di, dj) in [(1,0), (-1,0), (0,1), (0,-1)]:
                    if 0 <= i + di < n and 0 <= j + dj < n:
                        board[i + di][j + dj] = 1 - board[i + di][j + dj]
        show(i, board)

main()
