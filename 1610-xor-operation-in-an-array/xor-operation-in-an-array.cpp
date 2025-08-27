class Solution {
public:
    int xorOperation(int n, int start) {
        int result = 0 ,i = 0;

        while(n > 0){
            result ^= start + i;
            i += 2;
            n--; 
        }

        return result;
    }
};