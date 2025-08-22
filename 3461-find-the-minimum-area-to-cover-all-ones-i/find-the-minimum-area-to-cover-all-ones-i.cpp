class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int min_row = n, max_row = -1;
        int min_col = m, max_col = -1;

        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if(grid[i][j]==1){
                    min_row=min(i,min_row);
                    max_row=max(i,max_row);
                    min_col=min(j,min_col);
                    max_col=max(j,max_col);
                }
            }
        }

        return (max_row - min_row + 1) * (max_col - min_col + 1);
    }
};