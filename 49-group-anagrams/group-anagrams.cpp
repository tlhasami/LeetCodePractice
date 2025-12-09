class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;

        vector<vector<int>>freqs(strs.size() , vector<int>(27 , 0)) ;

        int n = strs.size();

        for (int i = 0 ; i < n ; i++){ // O(n*m)
            for (char& ch : strs[i]){
                ++freqs[i][ch-'a'];
            }
        }

        for (int i = 0 ; i < n ; i++){
            if(freqs[i][0] == -1)
                continue;

            vector<string>curr;

            curr.push_back(strs[i]);

            for (int j = i+1 ; j < n ; j++){
                if (freqs[i] == freqs[j]){
                    curr.push_back(strs[j]);
                    freqs[j][0] = -1;
                }
            }

            result.push_back(curr);
        }

        return result;
    }
};