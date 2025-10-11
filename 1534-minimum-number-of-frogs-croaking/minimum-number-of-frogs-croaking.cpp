class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int n = croakOfFrogs.size();
        if (n % 5 != 0) return -1;
        
        int frogs = 0, ans = 0;
        unordered_map<char, int> freq;
        
        for (char ch : croakOfFrogs) {
            if (ch == 'c') frogs++, freq['c']++;
            else if (ch == 'r' && freq['c'] > freq['r']) freq['r']++;
            else if (ch == 'o' && freq['r'] > freq['o']) freq['o']++;
            else if (ch == 'a' && freq['o'] > freq['a']) freq['a']++;
            else if (ch == 'k' && freq['a'] > freq['k']){
                ans = max(ans, frogs);
                frogs--;
                freq['k']++;
            }
            else return -1;
        }
        return frogs==0 ? ans : -1;
    }
};