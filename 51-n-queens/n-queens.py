class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def isSafe(board, row, col):
            # Check upward in the same column
            for i in range(row):
                if board[i][col] == 'Q':
                    return False

            # Check upper-left diagonal
            i, j = row - 1, col - 1
            while i >= 0 and j >= 0:
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j -= 1

            # Check upper-right diagonal
            i, j = row - 1, col + 1
            while i >= 0 and j < n:
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j += 1

            return True

        def solve(row):
            if row == n:
                res.append(["".join(r) for r in board])
                return

            for col in range(n):
                if isSafe(board, row, col):
                    board[row][col] = 'Q'
                    solve(row + 1)
                    board[row][col] = '.'  # backtrack

        board = [["." for _ in range(n)] for _ in range(n)]
        res = []
        solve(0)
        return res
