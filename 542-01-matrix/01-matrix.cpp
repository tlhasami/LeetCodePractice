class Solution {
public:

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();

        queue<pair<int,int>>qu;
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < m ; j++){
                if (mat[i][j] == 0){
                    qu.push({i,j});
                } else{
                    mat[i][j] = INT_MAX;
                }
            }
        }

        while (!qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();

            for (int i = 0 ; i < 4 ; i++){
                int row = r + dx[i];
                int col = c + dy[i];

                if (row < 0 || col < 0 || row >= n || col >= m)
                    continue;

                if ( mat[row][col] == INT_MAX){
                    mat[row][col] = mat[r][c]+1; 
                    qu.push({row,col});
                }
                    
                
            }
            

        }    

        return mat;
    }
};