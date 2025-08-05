class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        int dx[8] = {-1,-1,-1, 0, 0, 1,1,1};
        int dy[8] = {-1, 0, 1,-1, 1,-1,0,1};

        q.push({0, 0});
        visited[0][0] = true;
        int steps = 1;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [x, y] = q.front(); q.pop();

                // If reached the target
                if (x == n - 1 && y == m - 1)
                    return steps;

                for (int dir = 0; dir < 8; dir++) {
                    int new_x = x + dx[dir];
                    int new_y = y + dy[dir];

                    if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m &&
                        !visited[new_x][new_y] && grid[new_x][new_y] == 0) {
                        
                        q.push({new_x, new_y});
                        visited[new_x][new_y] = true;
                    }
                }
            }
            steps++; // BFS level = 1 step
        }

        return -1;
    }
};
