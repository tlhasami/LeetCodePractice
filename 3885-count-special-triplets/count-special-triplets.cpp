class Solution {
public:
    int specialTriplets(vector<int>& nums) {

        const int MOD = 1000000007;
        int n = nums.size();
        long long triplets = 0;

        /*
        for (int k = n-1 ; k >= 0 ; k--){
            if (nums[k]%2)
                continue;

            for (int j = k-1 ; j >= 0  ; j--){
                for (int i = j-1 ; i >= 0 ; i--){
                    if (nums[i]%2)
                        continue;

                    if (nums[i] == nums[j]*2 && nums[k]== nums[j]*2)
                        ++triplets;
                }
            }
        }
        */

        unordered_map<int,int>before;
        unordered_map<int,int>after;

        for (int& num : nums)
            ++after[num];

        for (int& num:nums){
            --after[num];

            long long need = 2LL * num;

            if (after.find(num*2) != after.end())
                triplets = (triplets + 1LL * before[need] * after[need]) % MOD;

            ++before[num];
        }


        return triplets%MOD;
        
    }
};