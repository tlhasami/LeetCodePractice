class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq_1(26,0) ,freq_2(26,0);

        for (char alphabet : s)
            freq_1[alphabet - 'a'] ++;
        
        for (char alphabet : t)
            freq_2[alphabet - 'a'] ++;
        
        for (int i = 0 ; i < 26 ; i++){
            if (freq_1[i] != freq_2[i])
                return 'a' + i;
        }

        return ' ';
    }
};
