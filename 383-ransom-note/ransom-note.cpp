class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>freq ;
        
        for (char& ch : magazine)
            freq[ch]++;
        
        for (char& ch : ransomNote){
            if (freq.find(ch)!= freq.end()){
                if (freq[ch] >= 1) freq[ch]--;
                else return false;
            } else {
                return false;
            }
                
        }

        return true;
    }
};