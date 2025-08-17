class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int>result;

        for (int& num:nums){
            freq[num]++;
            if (freq[num] == 2)
                result.push_back(num);
        }

        return result;

    }
};