class Solution {
public:
    int dx[4] = {-1,0,1,0} ;
    int dy[4] = {0,1,0,-1} ;

    vector<vector<bool>> visited;


    int dfs(vector<vector<int>>& grid,int row,int col){
        if (row < 0 || row >= grid.size() || col < 0 ||col >= grid[0].size() || !grid[row][col]){
           // cout << " 1 " ;
            return 1;
        }

        if (visited[row][col]){
           // cout << " "<< visited[row][col] <<" ";
            return 0;
        }
        
        visited[row][col] = true;

        int count = 0;
        for (int k = 0 ; k < 4 ; k++){
            //cout <<" in ";
            count += dfs(grid , row + dx[k] , col + dy[k] );
        }

        return count;
    }


    int islandPerimeter(vector<vector<int>>& grid) {

        visited = vector<vector<bool>>(grid.size(),vector<bool>(grid[0].size(),false));

        for (int i = 0; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){

                if (grid[i][j]){
                    return dfs(grid,i,j);
                }

            }
        }

        return -1;


        
    }
};