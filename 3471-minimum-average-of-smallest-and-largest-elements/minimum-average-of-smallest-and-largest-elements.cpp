class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int n = nums.size();
        int left = 0 , right = n-1;

        double result = INT_MAX;
        while (left < right){

            if (result > (nums[left] + nums[right]) / 2.0)
                result =  (nums[left] + nums[right]) / 2.0;

            ++left , --right;
        }

        return result;
    }
};