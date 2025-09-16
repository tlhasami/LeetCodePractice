class Solution {
public:
    bool isVowel(char a){
        return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';
    }

    bool isValid(string word) {
        if (word.length() < 3) return false;

        bool vowel = false , consonant = false;
        for (char alpha : word){
            if (isalpha(alpha)){
                alpha = tolower(alpha);
                if (isVowel(alpha)){
                    vowel = true;
                } else {
                    consonant = true;
                }
            } else if (isdigit(alpha)){
                continue;
            } else {
                return false;
            }
        }



        return vowel && consonant;
    }
};