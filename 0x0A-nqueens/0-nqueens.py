#!/usr/bin/python3
"""
Program to solve Nqueens and display all solutions
    Arguments:
     Takes 1 integer for the size of the board.  Must be 4 or greater.

    Methods:
     printSolution: prints the solution index by index
     solveNQueens: recursively solves board by placing queens
        and checking if they are valid
     isSafe: checks to see if a queen can see another queen
"""
import sys
global N
if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    N = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    exit(1)

if N < 4:
    print("N must be at least 4")
    exit(1)


def printSolution(board):
    """
    Prints the index location of the queens
    """
    first = True
    print("[", end='')
    for row in range(N):
        for col in range(N):
            if board[row][col] == 1:
                if first is False:
                    print(", ", end='')
                print("[{},{}]".format(row, col), end='')
                first = False
    print("]")


def isSafe(board, row, col):
    """
    Checks to see if a queen can see another queen
    """
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def solveNQueens(board, col):
    """
    Recursively checks each spot to see if it is a valid board
    """
    if col == N:
        printSolution(board)
        return True

    result = False
    for i in range(N):

        if isSafe(board, i, col):
            board[i][col] = 1

            result = solveNQueens(board, col + 1) or result

            board[i][col] = 0

    return result

board = []
for row in range(N):
    board.append([])
    for col in range(N):
        board[row].append(0)

solveNQueens(board, 0)
