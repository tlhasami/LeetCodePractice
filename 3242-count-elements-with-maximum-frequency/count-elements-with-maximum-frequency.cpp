class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>freq;

        int maxi = INT_MIN;
        for (auto num: nums){
            freq[num] ++;
            maxi = max(maxi,freq[num]);
        }

        int result = 0;
        for (auto& [key , value]: freq)
            if (value == maxi) result+=value;

        return result;
        
    }
};