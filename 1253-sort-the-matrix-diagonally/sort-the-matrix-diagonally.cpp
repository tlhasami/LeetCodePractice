class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();

        for (int i = 0 ; i < n - 1; i++){

            vector<int> values;
            for (int j = i , k = 0 ; j < n && k < m ; j++ , k++){
                values.push_back(mat[j][k]);
                
            }
            

            sort(values.begin(),values.end());
            int idx = 0;
            for (int j = i , k = 0 ; j < n && k < m; j++ , k++){
                mat[j][k] = values[idx++];
            }
        }

        for (int i = 1 ; i < m - 1; i++){

            vector<int> values;
            for (int j = 0 , k = i ; j < n && k < m ; j++ , k++){
                values.push_back(mat[j][k]);
            
            }
            

            sort(values.begin(),values.end());
        
            int idx = 0;
            for (int j = 0 , k = i ; j < n && k < m ; j++ , k++){
                mat[j][k] = values[idx++];
            }
        }

        return mat;
    }
};