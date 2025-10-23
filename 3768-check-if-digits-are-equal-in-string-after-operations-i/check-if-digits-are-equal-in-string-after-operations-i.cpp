class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        for (int i = n-2 ; i > 0 ; i-- ){
            for (int j = 0 ; j < i+1 ; j++){
                int x =  (s[j] - '0');
                int y =  (s[j+1] - '0');

                s[j] ='0' + (x+y)%10 ;
                
            }
            //cout << s << endl;
        }

        return s[0] == s[1];
    }
};