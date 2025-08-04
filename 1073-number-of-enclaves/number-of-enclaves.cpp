class Solution {
public:

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>>& grid , int row, int col){
        if (row  < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != 1 )
            return ;

        grid[row][col] = -1;

        for (int k = 0 ; k < 4 ; k++){
            dfs(grid,row + dx[k] , col + dy[k]);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();

        for (int i = 0 ; i < n ; i++){
            dfs(grid,i,0);
            dfs(grid,i,m-1);
        }
        for (int i = 0 ; i < m ; i++){
            dfs(grid,0,i);
            dfs(grid,n-1,i);
        }

        int count = 0;

        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                count += grid[i][j] == 1 ? 1 : 0 ; 
            }
        }

        return count;
    }
};