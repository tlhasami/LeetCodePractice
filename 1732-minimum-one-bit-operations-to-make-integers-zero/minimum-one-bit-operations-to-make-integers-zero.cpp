class Solution {
public:
    /*
        When n=2 k
    , it needs 2 k+1 −1 operations. Other k+1-bit integer, say 2 
    k
    +x.
    Consider the number of operations from 2 
    k
    +x to 2 
    k
    
    */
    int minimumOneBitOperations(int n) {
        
       int res = 0;
        while (n) {
            res ^= n;
            n >>= 1;
        }
        return res;
        
    }
};