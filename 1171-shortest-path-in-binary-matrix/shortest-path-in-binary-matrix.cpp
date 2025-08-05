class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int dx[8] = {-1,-1,-1, 0, 0, 1,1,1};
        int dy[8] = {-1, 0, 1,-1, 1,-1,0,1};

        queue<tuple<int, int, int>> q; // (x, y, steps)
        q.push({0, 0, 1});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [x, y, steps] = q.front(); q.pop();

            if (x == n - 1 && y == m - 1)
                return steps;

            for (int dir = 0; dir < 8; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    !visited[nx][ny] && grid[nx][ny] == 0) {
                    visited[nx][ny] = true;
                    q.push({nx, ny, steps + 1});
                }
            }
        }

        return -1;
    }
};
