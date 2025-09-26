class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //int count = 0 , n = nums.size();
        // for (int i = 0 ; i < n ; i++){
        //     for (int j = i + 1 ; j < n ; j++){
        //         for(int k = j + 1 ; k < n ; k++){
        //             if (nums[i]+nums[j] > nums[k]
        //              && nums[k]+nums[i] > nums[j] 
        //              && nums[j]+nums[k] > nums[i])
        //              count++;
        //         }
        //     }
        // }
        // return count;

        sort(nums.begin(), nums.end());
        int n = nums.size(), count = 0;
        
        for (int k = n - 1; k >= 2; k--) {   
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};