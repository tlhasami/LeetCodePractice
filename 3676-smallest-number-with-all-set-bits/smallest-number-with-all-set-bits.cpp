class Solution {
public:
    int smallestNumber(int n) {
        if (n == 1) return 1;
        int val = 1 ;
        for (int i = 1 ; val <= n ; i++)
            val <<= 1;
        
        return val-1;

        
    }
};