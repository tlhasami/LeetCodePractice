class Solution {
public:
    int alternatingSum(vector<int>& nums) {

        int result = 0;
        bool invert = true;
        for (int num : nums){

            result += invert ? num : -num;
            invert = !invert;
        }

        return result;
        
    }
};