class Solution {
public:

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>>& board, int r, int c, int n, int m) {
        board[r][c] = 0;

        for (int i = 0; i < 4; i++) {
            int row = r + dx[i];
            int col = c + dy[i];

            if (row < 0 || col < 0 || row >= n || col >= m || board[row][col] != 1)
                continue;

            dfs(board, row, col, n, m);
        }
    }

    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size() , m = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 1)     dfs(board, i, 0, n, m);
            if (board[i][m-1] == 1)   dfs(board, i, m-1, n, m);
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 1)     dfs(board, 0, i, n, m);
            if (board[n-1][i] == 1)   dfs(board, n-1, i, n, m);
        }

        int landCells = 0;
        for (auto& line : board){
            for (auto& value : line){
                landCells += value;
            }
        }

        return landCells;
    }
};