class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            int total = 0;
            for (int j = i; j < n; ++j) {
                total += nums[j];
                if (total == k) {
                    count++;
                }
            }
        }

        return count;
    }
};
