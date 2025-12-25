class Solution {
public:
    bool isValidRow(vector<vector<int>>& matrix , int row , const int& n){
        vector<bool>freq(n , false);

        for (int i = 0 ; i < n ; i++){
            if (matrix[row][i] > n) return false;
            freq[matrix[row][i]-1] = true;
        }

        for (bool val : freq)
            if (!val) return false;

        return true;
    }

    bool isValidCol(vector<vector<int>>& matrix , int col , const int& n){
        vector<bool>freq(n , false);

        for (int i = 0 ; i < n ; i++){
            if (matrix[i][col] > n) return false;
            freq[matrix[i][col]-1] = true;
        }

        for (bool val : freq)
            if (!val) return false;

        return true;
    }

    bool checkValid(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 0 ; i < n ;i++)
            if (!isValidRow(matrix,i,n) || !isValidCol(matrix,i,n))
                return false;

        return true;
    }
};