class Solution {
public:
    long long int dfs(vector<vector<int>>& grid, int row,int col , const int& n , const int& m) {
        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0)
            return 0;

        int toSend = grid[row][col];
        grid[row][col] = 0;

        return toSend+
                dfs(grid,row -1, col , n , m)+
                dfs(grid,row +1, col , n , m)+
                dfs(grid,row , col+1 , n , m)+
                dfs(grid,row , col-1, n , m);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size() , islands = 0;

        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (grid[i][j] > 0 && dfs(grid,i,j,n,m)%k == 0 )
                    ++islands;
            }
        }

        return islands;
    }
};