class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        unordered_map<string , int>freq;

        for (string& word: words){
            freq[word]++;
        }

        for (auto [word,haveCount] : freq){
            int i = 0 , n = s.length() , j = 0 , m = word.length();

            while (i < n && j < m){
                if (s[i] == word[j]){
                    i++;j++;
                }
                else 
                    i++;
                
            }

            count = j == m ? count+haveCount : count;
        }

        return count;

        // unordered_map<char,vector<int>>freq;
        // int n = s.length();

        // for (int i = 0 ; i < n ; i++)
        //     freq[ch].push_back(i);
        
        // int count = 0;
        // for (string& word : words){
        //     unordered_map<char,int> toCheck = freq;

        //     int m = word.length();
        //     bool match = true;
        //     for (int i = 0 ; i < m ; i++){
        //         if (toCheck.find(word[i]) == toCheck.end()){
        //             match = false;
        //             break;
        //         }

                
                    

        //     }

        //     if (match) count++;
        // }

        // return count;
    }
};