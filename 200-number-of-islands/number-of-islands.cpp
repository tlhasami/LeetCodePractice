class Solution {
public:
    void dfs(vector<vector<char>>& grid , int row , int col , const int& n , const int& m){
        if (row >= n || col >= m || row < 0 || col < 0 || grid[row][col]=='0')
            return; 
        
        
        
        grid[row][col] = '0';

        dfs(grid,row -1, col , n , m);
        dfs(grid,row +1, col , n , m);
        dfs(grid,row , col+1 , n , m);
        dfs(grid,row , col-1, n , m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() , m =grid[0].size() , islands = 0;

        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (grid[i][j] == '1'){
                    ++islands;
                    dfs(grid,i,j,n,m);
                }
            }
        }

        return islands;

    }
};