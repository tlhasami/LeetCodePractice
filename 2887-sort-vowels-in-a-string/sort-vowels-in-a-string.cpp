class Solution {
public:
    bool isVowel(char ch){
        if (ch == 'A' || ch=='E' || ch == 'I' || ch=='O' || ch=='U'
            || ch == 'a' || ch=='e' || ch == 'i' || ch=='o' || ch=='u'){
                return true;
            }
        return false;
    }
    string sortVowels(string s) {
        vector<char>vowals;

        for(auto& a:s){
            if (isVowel(a)){
                vowals.push_back(a);
            }
        }

        sort(vowals.begin() , vowals.end());

        int idx = 0;
        for (auto& a:s){
            if (isVowel(a)){
                a = vowals[idx++];
            }
        }

        return s;
    }
};