class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>grid(n,vector(n,0));
        
        for (auto& query : queries){
            int r1 = query[0] , c1 = query[1] , r2 = query[2] , c2 = query[3];
            for (int i = r1 ; i <= r2 ; i++){
                for (int j = c1 ; j <= c2 ; j++){
                    ++grid[i][j];
                }
            }

            /*
            for (int i = 0 ; i < n ; i++){
                for (int j = 0 ; j < n ; j++){
                    cout << grid[i][j] << " ";
                } cout << endl;
            }
            */
        }

        return grid;
    }
};