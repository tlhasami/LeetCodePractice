class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        

        bool found = false;
        do {

            found = false;
            for (int& num : nums){
                if (num == original) {
                    original *= 2;
                    found = true;
                }
            }
            
        } while (found);

        return original;

    }
};