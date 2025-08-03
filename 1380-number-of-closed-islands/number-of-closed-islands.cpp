class Solution {
public:
    vector<vector<bool>> visited;    
    int dx[4] = {-1, 1, 0, 0}; // up, down, left, right
    int dy[4] = {0, 0, -1, 1};

    bool dfs(vector<vector<int>>& grid, int n , int m ,int row , int col){
        if (row >= n || col >= m || row < 0 || col < 0)
            return false;
        
        if (grid[row][col] || visited[row][col])
            return true;
        
        visited[row][col] = true;

        bool isClosed = true;

        for (int i = 0; i < 4; i++) {
            if (!dfs(grid, n, m, row + dx[i], col + dy[i]))
                isClosed = false;
        }

        return isClosed;

    }

    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size() , m = grid[0].size();

        visited = vector<vector<bool>>(n, vector<bool>(m, false));

        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (grid[i][j] == 0 && visited[i][j] == false && dfs(grid,n,m,i,j)){
                    count++;
                }
            }
        } 

        return count;   
    }
};