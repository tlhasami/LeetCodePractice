class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int>map;
        for (int i = 0 ; i < 26; i++){
            map[order[i]] = i;
        }

        int n = words.size();
        for (int i = 0; i < n-1 ; i++){
            string x = words[i];
            string y = words[i+1];

            int length = min(x.length() , y.length());
            bool found = false;

            for (int j = 0 ; j < length ; j++){
                if (map[x[j]] < map[y[j]]){
                    found = true;
                    break;
                }
                
                if (map[x[j]] == map[y[j]])
                    continue;

                if (map[x[j]] > map[y[j]])
                    return false;
            }

            if (!found && x.length() > y.length())
                return false;

            

        }

        return true;
    }
};