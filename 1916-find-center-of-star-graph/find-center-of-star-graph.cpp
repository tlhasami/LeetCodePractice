class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        int n = edges.size() ;
        unordered_map<int,int>freq;

        for (auto& edge : edges){
            freq[edge[0]]++;
            freq[edge[1]]++;
        }

        for (auto& [key,value] : freq){
            cout << value << " ";
            if (value == n) return key;
        }
            
        

        return -1;
    }
};