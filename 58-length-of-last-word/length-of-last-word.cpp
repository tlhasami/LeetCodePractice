class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0 ;
        bool start = false;

        for (int i = s.length() - 1; i >= 0 ; i-- ){
            if (!start && s[i] == ' ')
                continue;
            else if (start && s[i] == ' ')
                return count;
            else {
                start = true;
                count ++;
            }
        }

        return count;
    }
};