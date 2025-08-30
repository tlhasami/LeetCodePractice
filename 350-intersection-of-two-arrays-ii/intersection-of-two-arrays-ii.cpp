class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;

        unordered_map<int ,int> freq;

        for (auto& num : nums1){
            freq[num]++;
        }

        for (auto& num : nums2){
            if (freq.find(num) != freq.end() && freq[num] > 0){
                result.push_back(num);
                freq[num]--;
            }
        }

        return result;
    }
};