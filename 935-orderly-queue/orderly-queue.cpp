class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1){
             int n = s.length();
            string lex = s;  

            for (int j = 0; j < n; j++) {
           
                char ch = s[0];  
                for (int i = 0; i < n - 1; i++) {
                    s[i] = s[i + 1];
                }
                s[n - 1] = ch;   
                if (s < lex) {   
                    lex = s;
                }
            }

            return lex;  
            
            
        }
        else {
            sort(s.begin() , s.end());
        }

        return s;
    }
};