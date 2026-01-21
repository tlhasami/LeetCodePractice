class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>result;
        result.reserve(n);

        for (int num : nums){
            if (num %2 == 0){
                result.push_back(-1);
                continue;
            }

            for (int binaryIndex = 31; binaryIndex > -1 ; --binaryIndex){
                int temp = num ^ (1 << binaryIndex) ;

                if ((temp | temp+1) == num){
                    result.push_back(temp);
                    break;
                    
                }

            }
            
        }
        
        return result;
    }
};