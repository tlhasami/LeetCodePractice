class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int left = 0 , right = nums.size()-1;
        
        int pairMaxiumum = INT_MIN;
        while (left < right){
            pairMaxiumum = max(pairMaxiumum , nums[left++] + nums[right--]);
        }

        return pairMaxiumum;
    }
};