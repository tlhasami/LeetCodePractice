class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();
        if (n % 5 != 0) return -1;
        
        int frogs = 0, ans = 0;
        vector<int> freq(26 , 0);
        
        for (char ch : croakOfFrogs) {
            if (ch == 'c') frogs++, freq['c'-'a']++;
            else if (ch == 'r' && freq['c'-'a'] > freq['r'-'a']) freq['r'-'a']++;
            else if (ch == 'o' && freq['r'-'a'] > freq['o'-'a']) freq['o'-'a']++;
            else if (ch == 'a' && freq['o'-'a'] > freq['a'-'a']) freq['a'-'a']++;
            else if (ch == 'k' && freq['a'-'a'] > freq['k'-'a']){
                ans = max(ans, frogs);
                frogs--;
                freq['k'-'a']++;
            }
            else return -1;
        }
        return frogs==0 ? ans : -1;
    }
};