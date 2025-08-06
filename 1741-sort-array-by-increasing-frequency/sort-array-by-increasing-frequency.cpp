class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int n : nums)
            freq[n]++;

        vector<pair<int,int>> temp;
        for (auto [val, count] : freq) {
            temp.push_back({count, val});
        }

        sort(temp.begin(), temp.end(), [](pair<int,int>& a, pair<int,int>& b) {
            if (a.first != b.first)
                return a.first < b.first;
            return a.second > b.second;
        });


        int i = 0;
        for (auto [count, val] : temp) {
            for (int j = 0; j < count; j++) {
                nums[i++] = val;
            }
        }

        return nums;
    }
};
