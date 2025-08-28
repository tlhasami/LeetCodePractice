class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        //vector<vector<int>> result;
        for (int i = 0 ; i < n ; i++){

            vector<int> values;
            for (int j = i , k = 0 ; j < n && k < n ; j++ , k++){
                values.push_back(grid[j][k]);
                
            }
            

            sort(values.begin(),values.end());
            reverse(values.begin(),values.end());

            int idx = 0;
            for (int j = i , k = 0 ; j < n && k < n; j++ , k++){
                grid[j][k] = values[idx++];
            }
        }

        for (int i = 1 ; i < n ; i++){

            vector<int> values;
            for (int j = 0 , k = i ; j < n && k < n ; j++ , k++){
                values.push_back(grid[j][k]);
            
            }
            

            sort(values.begin(),values.end());
        
            int idx = 0;
            for (int j = 0 , k = i ; j < n && k < n ; j++ , k++){
                grid[j][k] = values[idx++];
            }
        }

        return grid;
    }
};