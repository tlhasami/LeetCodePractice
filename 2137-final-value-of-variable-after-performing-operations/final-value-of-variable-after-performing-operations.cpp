class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (string& operation : operations){
            if (operation == "++X") {
                ++X;
            } else if (operation == "--X") {
                --X;
            } else if (operation == "X++") {
                X++;
            } else {
                X--;
            }
        }

        return X;
    }
};