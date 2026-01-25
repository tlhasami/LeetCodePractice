class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        if (k > n) 
            return 0;

        sort(nums.begin(),nums.end());

        int index = 0;
        int minDifference = INT_MAX;

        while ( index+k-1 < n){
            minDifference = min(minDifference , nums[index+k-1] - nums[index]);
            ++index;
        }

        return minDifference;

    }
};