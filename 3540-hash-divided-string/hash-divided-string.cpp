class Solution {
public:
    string stringHash(string s, int k) {
        
        int index = 0 , n = s.length();
        string result = "";

        while (index < n){
            
            int sum = 0;
            for(int j = 0; index < n && j < k ; index++ , j++  ){
                sum += s[index] - 'a';
            }

            //cout << sum << "\n";

            result += ('a' + (sum%26));
        }

        return result;
    }
};