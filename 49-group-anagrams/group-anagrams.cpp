// class Solution {
// public:
    
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>>result;

//         vector<vector<int>>freqs(strs.size() , vector<int>(27 , 0)) ;

//         int n = strs.size();

//         for (int i = 0 ; i < n ; i++){ // O(n*m)
//             for (char& ch : strs[i]){
//                 ++freqs[i][ch-'a'];
//             }
//         }

//         for (int i = 0 ; i < n ; i++){
//             if(freqs[i][0] == -1)
//                 continue;

//             vector<string>curr;

//             curr.push_back(strs[i]);

//             for (int j = i+1 ; j < n ; j++){
//                 if (freqs[i] == freqs[j]){
//                     curr.push_back(strs[j]);
//                     freqs[j][0] = -1;
//                 }
//             }

//             result.push_back(curr);
//         }

//         return result;
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> anagramGroups;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            // Count character frequencies
            for (char c : strs[i]) {
                freq[c - 'a']++;  // Corrected: Only increment
            }

            // Convert frequency vector to a string key
            string key = "";
            for (int count : freq) {
                key += to_string(count) + "#";
            }

            anagramGroups[key].push_back(strs[i]);
        }

        // Convert hashmap to output format
        vector<vector<string>> ans;
        for (auto& group : anagramGroups) {
            ans.push_back(group.second);
        }

        return ans;
    }
};