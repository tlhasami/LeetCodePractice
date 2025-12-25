class Solution {
public:

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<char>>& board, int r, int c, int n, int m) {
        board[r][c] = 'S';

        for (int i = 0; i < 4; i++) {
            int row = r + dx[i];
            int col = c + dy[i];

            if (row < 0 || col < 0 || row >= n || col >= m || board[row][col] != 'O')
                continue;

            dfs(board, row, col, n, m);
        }
    }


    void solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')     dfs(board, i, 0, n, m);
            if (board[i][m-1] == 'O')   dfs(board, i, m-1, n, m);
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O')     dfs(board, 0, i, n, m);
            if (board[n-1][i] == 'O')   dfs(board, n-1, i, n, m);
        }


        for (auto& line : board){
            for (auto& val : line){
                if (val == 'S')
                    val = 'O';
                else 
                    val = 'X';
            }
        }

    }
};