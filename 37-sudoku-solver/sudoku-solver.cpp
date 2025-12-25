class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        // row & column check
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) return false;
            if (board[i][col] == ch) return false;
        }

        // correct 3x3 box start
        int r = (row / 3) * 3;
        int c = (col / 3) * 3;

        // 3x3 check
        for (int i = r; i < r + 3; i++)
            for (int j = c; j < c + 3; j++)
                if (board[i][j] == ch)
                    return false;

        return true;
    }

    bool solveSudukoHelper(vector<vector<char>>& board, int row = 0, int col = 0) {
        if (row == 9) return true;

        if (board[row][col] != '.') {
            if (col == 8)
                return solveSudukoHelper(board, row + 1, 0);
            else
                return solveSudukoHelper(board, row, col + 1);
        }

        for (char ch = '1'; ch <= '9'; ch++) {
            if (isValid(board, row, col, ch)) {
                board[row][col] = ch;

                if (col == 8) {
                    if (solveSudukoHelper(board, row + 1, 0))
                        return true;
                } else {
                    if (solveSudukoHelper(board, row, col + 1))
                        return true;
                }

                // backtrack
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudukoHelper(board);
    }
};