class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string current ;

        int countNodes = 1;

        while (getline(ss,current,',')){
            countNodes--;
            if (countNodes < 0) return false;

            if (current != "#") countNodes+=2;

        }

        return countNodes == 0;

    }
};