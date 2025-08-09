class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>freq;

        for(auto& edge:edges){
            freq[edge[0]]++;
            freq[edge[1]]++;
        }

        auto max_pair = max_element(freq.begin(), freq.end(),[]
        (const auto &a, const auto &b) {
            return a.second < b.second; // Compare by value
        }
    );

        return max_pair->first;
    }
};