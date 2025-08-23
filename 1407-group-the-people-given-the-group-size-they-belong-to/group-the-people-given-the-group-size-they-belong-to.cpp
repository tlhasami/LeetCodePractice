class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {

        unordered_map<int,vector<int>> freq;
        int n = groupSizes.size();

        for (int i = 0 ; i < n ;i ++){
            freq[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> result;
        for(auto& [key , indexes] : freq){
            for (int i = 0; i < indexes.size(); i += key) {
                vector<int> group;
                for (int j = i; j < i + key; j++) {
                    group.push_back(indexes[j]);
                }
                result.push_back(group);
            }

        }

        return result;

    }
};