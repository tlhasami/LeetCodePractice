class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>freq;

        for (auto& alphabet: allowed){
            freq[alphabet]++;
        }

        int count = 0;

        for(auto& word: words){
            unordered_map<char,int>checking;

            for(auto& alphabet: word){
                checking[alphabet]++;
            }

            if (freq.size() < checking.size())
                continue;
            
            bool present = true;
            for (auto& [key,val] : checking){
                if (freq.find(key) == freq.end()){
                    present = false;
                    break;
                }
            }

            if (present)
                count++;
        }

        return count;

        
    }
};