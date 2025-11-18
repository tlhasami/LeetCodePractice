class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size() , i = 0;
        
        while (i < n-1){
            if (bits[i] == 1) i+=2 ;
            else i++;
        }

        if (i == n-2 && bits[i] == 1) return false;
        if (i == n-1 && bits[i] == 0) return true;
        
        return false;
    }
};