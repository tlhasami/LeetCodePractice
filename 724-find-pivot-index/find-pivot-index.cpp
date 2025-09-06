class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();

        if (n==1) return 0;
        
        vector<int>leftSum(nums.size() , 0);
        vector<int>rightSum(nums.size() , 0);

        //left sum
        leftSum[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            leftSum[i] = nums[i] + leftSum[i-1];
        }

        // for (auto& num : leftSum) cout << num << " ";
        // cout << endl;

        //Right sum
        rightSum[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            rightSum[i] = nums[i] + rightSum[i+1];
        }

        // for (auto& num : rightSum) cout << num << " ";
        // cout << endl;

        for (int i = 0 ; i < n ; i++){
            if (i == 0 && rightSum[i+1] == 0){
                return 0;
            } else if (i == n - 1 && leftSum[i-1] == 0 ){
                return n-1;
            }
            else if (i > 0 && i < n-1 && leftSum[i-1] == rightSum[i+1])
                return i;
        }

        return -1;
    }
};