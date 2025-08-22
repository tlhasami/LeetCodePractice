class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int min_row = -1 , max_row = -1 , min_col = -1 , max_col = -1 ;
        int n = grid.size() , m = grid[0].size();

        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (grid[i][j] == 1 && min_row == -1){
                    min_row = i;
                    max_row = i;
                } else if (min_row != -1 && grid[i][j] == 1){
                    max_row = i;
                }
            }
        }

        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (grid[j][i] == 1 && min_col == -1){
                    min_col = i;
                    max_col = i;
                } else if (min_col != -1 && grid[j][i] == 1){
                    max_col = i;
                }
            }
        }

        return (max_row - min_row + 1) * (max_col - min_col + 1);
    }
};