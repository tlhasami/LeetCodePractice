class Solution {
public:
    bool rowCheck(vector<vector<int>>& mat , int row , int col){
        int n = mat.size() , m = mat[0].size();
        for (int i = 0 ; i < n ; i++){
            if (mat[i][col] == 1 && i!=row)
                return false;
        }

        return true;
    }

    bool colCheck(vector<vector<int>>& mat , int row , int col){
        int n = mat.size() , m = mat[0].size();

        for (int i = 0 ; i < m ; i++){
            if (mat[row][i] == 1 && i!=col)
                return false;
        }

        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();

        int specialCounts = 0;
        for (int i = 0 ; i < n ; i++ ){
            for (int j = 0 ; j < m ; j++){

                if (mat[i][j] == 1 && rowCheck(mat , i , j) && colCheck(mat , i , j))
                    ++specialCounts;
            }
        }

        return specialCounts;

    }
};