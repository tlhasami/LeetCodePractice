class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>freq;
        for (int& num: nums){
            freq[num]++;
        }

        vector<int>result;
        for (auto &[key,val] : freq){
            if (val > 1) result.push_back(key);
        }

        return result;
    }
};