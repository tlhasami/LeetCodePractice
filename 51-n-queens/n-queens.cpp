class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        int N = board.size();
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j]== 'Q') return false;
        }

        for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
            if (board[i][j]== 'Q') return false;
        }

        return true;
    }


    void solver(vector<vector<string>>& result ,vector<string>& curr,int row = 0){
        int N = curr.size();

        if (row == N){
            result.push_back(curr);
            return;
        }

        for (int col = 0 ; col < N ; col++){
            if (isSafe(curr,row,col)){
                curr[row][col] = 'Q';
                solver(result,curr,row+1);
                curr[row][col] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> curr(n , string(n,'.'));

        solver(result,curr);

        return result;
    }
};