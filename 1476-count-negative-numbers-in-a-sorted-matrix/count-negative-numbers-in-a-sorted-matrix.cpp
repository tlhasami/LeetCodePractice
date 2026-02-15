class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int m = grid.size() , n = grid[0].size();

        int count = 0;
        
        for (int i = 0 ; i < m ; i++){
            for (int j = n-1 ; j > -1 ; j-- ){
                if (grid[i][j] > -1)
                    break;
                
                count++;
            }
        }

        return count;
    }
};