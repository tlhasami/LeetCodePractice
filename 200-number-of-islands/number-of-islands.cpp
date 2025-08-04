class Solution {
public:
    int dx[4] = {-1, 1, 0, 0}; // up, down, left, right
    int dy[4] = {0, 0, -1, 1};
    vector<vector<bool>> visited;

    void bfs(vector<vector<char>>& grid, int row, int col) {
        visited[row][col] = true;
        queue<pair<int,int>> q;
        q.push({row,col});

        int n = grid.size(), m = grid[0].size();

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for (int k = 0 ;k < 4 ;k++){
                int newPos_x = x + dx[k];
                int newPos_y = y + dy[k];
                if (newPos_x >= 0 && newPos_y >= 0 && newPos_x < n && newPos_y < m && !visited[newPos_x][newPos_y] && grid[newPos_x][newPos_y]  == '1'){
                    visited[newPos_x][newPos_y] = true;
                    q.push({newPos_x, newPos_y});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;

        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (!visited[i][j] && grid[i][j] == '1'){
                    bfs(grid,i,j);
                    count++;
                }
            }
        }

        return count; 
    }
};
