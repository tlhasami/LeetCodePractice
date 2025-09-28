class Solution {
public: 
    bool isSafe(vector<vector<bool>>& board, int row, int col) {
        int N = board.size();
        for (int i = 0; i < row; i++) {
            if (board[i][col]) return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j]) return false;
        }

        for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
            if (board[i][j]) return false;
        }

        return true;
    }


    void placement(vector<vector<bool>>&board , int& count , int r = 0){
        if(r == board.size()){
            count++;
            return ;
        }   

        int n = board.size();
        for (int col = 0 ; col < n ; col++){
            if (isSafe(board,r,col)){
                board[r][col] = true;
                placement(board,count,r+1);
                board[r][col] = false;
            }
        }

    }

    int totalNQueens(int n) {
        int count = 0 ;
        vector<vector<bool>> board(n , vector<bool>(n,false));

        placement(board,count);
        return count;

    }
};