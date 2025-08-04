class Solution {
public:
    int dx[4] = {-1, 1, 0, 0}; // up, down
    int dy[4] = {0, 0, -1, 1}; // left, right

    void dfs(vector<vector<char>>& grid, int n, int m, int row, int col) {
        // Boundary and condition check
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != 'O')
            return;

        grid[row][col] = 'S'; // Temporarily mark safe

        for (int i = 0; i < 4; i++) {
            dfs(grid, n, m, row + dx[i], col + dy[i]);
        }
    }

    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return;
        int m = grid[0].size();

        // Run DFS from all 'O's on the border
        for (int i = 0; i < n; i++) {
            dfs(grid, n, m, i, 0);         // left border
            dfs(grid, n, m, i, m - 1);     // right border
        }

        for (int j = 0; j < m; j++) {
            dfs(grid, n, m, 0, j);         // top border
            dfs(grid, n, m, n - 1, j);     // bottom border
        }

        // Final processing: flip and restore
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S')
                    grid[i][j] = 'O'; // restore safe
                else if (grid[i][j] == 'O')
                    grid[i][j] = 'X'; // surrounded
            }
        }
    }
};
