class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;

        for (auto& num:nums)
            count += (num%3)? 1 : 0; 
        
        return count;
    }
};