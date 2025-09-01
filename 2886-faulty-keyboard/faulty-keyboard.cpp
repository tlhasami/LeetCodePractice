class Solution {
public:
    string finalString(string s) {
        int current = 0 , n = s.length();
        string result = "";
        for (int i = 0 ; i < n ; i++){
            if (s[i] == 'i')
                reverse(result.begin() , result.end());
            else 
                result+=s[i];
        }

        return result;
    }
};