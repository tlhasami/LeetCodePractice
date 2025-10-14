class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>result;
        result.reserve(n);

        for (int i = 0 ; i < n ; i++){
            int nextGreaterVal = nums[i] , j = (i+1)%n;

            while (nums[i] >= nums[j] && i!=j){
                j = (j+1)%n;
            }

            if (i!=j)
                result.push_back(nums[j]);
            else
                result.push_back(-1);
        }

        return result;

    }
};