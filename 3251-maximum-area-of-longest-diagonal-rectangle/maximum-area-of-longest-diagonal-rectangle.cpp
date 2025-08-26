class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        int n = dimensions.size();  
        int longest = INT_MIN , idx = -1 ;
        for (int i = 0 ; i < n ; i++){
            int current = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1] ;
            if ( current > longest ) { 
                longest = current;
                idx = i;
            } else if (current == longest && ( dimensions[i][0] * dimensions[i][1] ) > (dimensions[idx][0] * dimensions[idx][1]) ){
                longest = current;
                idx = i;
            }
        }

        return dimensions[idx][0] * dimensions[idx][1]; 
    }
};