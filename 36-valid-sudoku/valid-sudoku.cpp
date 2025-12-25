class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col) {
        char ch = board[row][col];

        // row & column
        for (int i = 0; i < 9; i++) {
            if (i != col && board[row][i] == ch) return false;
            if (i != row && board[i][col] == ch) return false;
        }

        int r = (row / 3) * 3;
        int c = (col / 3) * 3;

        for (int i = r; i < r + 3; i++)
            for (int j = c; j < c + 3; j++) {
                if (i == row && j == col) continue;
                if (board[i][j] == ch) return false;
            }

        return true;
    }



    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.')
                    continue;
                
                if (!isValid(board,i,j))
                    return false;
                
            }
        
        return true;
    }
};
