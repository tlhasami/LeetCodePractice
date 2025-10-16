class Solution {
public:
    string freqAlphabets(string s) {
        string result = "";
        int idx = s.length()-1 ;

        while (idx >= 0){
            char number = 0;
            if (s[idx] == '#'){
                int n = s[idx-2] - '0' ;
                n = n*10 + s[idx-1] - '0' ;
                number = 'a' + n-1;
                idx-=2;
            } else if (isdigit(s[idx])) {
                number =  'a' + s[idx] - '0' - 1;
            }

            idx--;

            result+=number;

        }
        reverse(result.begin() , result.end());
        return result;
    }
};