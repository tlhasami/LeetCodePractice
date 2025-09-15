class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        vector<bool>broken(26, false);

        for (char alpha : brokenLetters ){
            broken[alpha-'a'] = true;
        }

        stringstream ss(text);
        string part;

        int wordCount = 0;
        while(ss >> part){

            bool found = false;
            for (char alpha : part){
                if (broken[alpha-'a']){
                    found = true;
                    break;
                }
            }

            if (!found){
                wordCount++;
            }
        }

        return wordCount;
    }
};