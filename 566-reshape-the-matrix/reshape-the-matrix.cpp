class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size()*mat[0].size() != r*c) return mat;

        vector<vector<int>>result(r, vector<int>(c , -1));

        int c_r = 0 , c_c = 0;
        for (auto& line:mat){
            for (auto& val:line){
                if (c_r < r && c_c < c){
                    result[c_r][c_c] = val;
                } else if (c_r < r){
                    result[c_r][c_c] = val;
                } else {
                    result[c_r][c_c] = val;
                }
                c_c = (c_c+1)%c;
                if (!c_c){
                    c_r = (c_r+1)%r;
                }
            }
        }

        return result;
    }
};