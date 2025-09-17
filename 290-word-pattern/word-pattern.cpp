class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> checker;
        stringstream ss(s);
        string part;

        int i = 0;
        while(ss>>part){
            //cout << part<<endl;
            if (checker.find(pattern[i]) == checker.end()){
                for (auto& [key , value]: checker){
                    if (value == part)
                        return false;
                }
                checker[pattern[i]] = part ;
            } else if (checker[pattern[i]] != part){
                    return false;
            }

            i++;
        }

        if (i == pattern.length()){
            return true;
        }

        return false;

    }
};