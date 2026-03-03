class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        vector<int>left = nums , right = nums;
        int n = nums.size();

        for (int i = 1 ; i < n ; i++){
            left[i] = left[i]+left[i-1];
        }

        for (int i = n-2 ; i >= 0 ; i--){
            right[i] = right[i+1] + right[i];
        }

        for (int i = 0 ; i < n ; i++){
            nums[i] = abs(left[i] - right[i]);
        }

        return nums;
    }
};