class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        for (auto& letter: letters){
            if (letter > target && target!=letter)
                return letter;
        }

        return letters[0];
    }
};