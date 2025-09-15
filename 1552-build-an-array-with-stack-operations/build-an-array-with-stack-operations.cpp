class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        int value = 1;
        vector<string> result;
        
        for (int num : target){
            if (value == num){
                result.push_back("Push");
                value++;
            } else {
                while (value!=num){
                    result.push_back("Push");
                    result.push_back("Pop");
                    value++;
                }
                result.push_back("Push");
                value++;
            }
        }

        return result;
    }
};