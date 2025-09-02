class Solution {
public:
    int scoreOfString(string s) {
        int n = s.length() , result = 0;
        for (int i = 1 ; i < n ; i++){
            result += abs(s[i-1] - s[i]);
        }
        return result;
    }
};