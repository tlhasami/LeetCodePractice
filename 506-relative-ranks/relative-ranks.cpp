class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>>sr_idx;

        int n = score.size();
        for (int i = 0 ; i < n ; i++){
            sr_idx.push_back({score[i] , i});
        }

        // Sort in decreasing order by score
        sort(sr_idx.begin(), sr_idx.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        vector<string> positions (n , "");

        

        for (int i = 0; i < n; i++) {
            if (i == 0)
                positions[sr_idx[i].second] = "Gold Medal";
            else if (i == 1)
                positions[sr_idx[i].second] = "Silver Medal";
            else if (i == 2)
                positions[sr_idx[i].second] = "Bronze Medal";
            else
                positions[sr_idx[i].second] = to_string(i + 1);
        }

        return positions;

    }
};