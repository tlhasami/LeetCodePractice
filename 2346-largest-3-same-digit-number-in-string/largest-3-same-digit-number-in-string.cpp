class Solution {
public:
    string largestGoodInteger(string num) {
        string largest = "";
        int n = num.size();
        
        for (int i = 0; i <= n - 3; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string triple = string(3, num[i]);
                if (triple > largest) {
                    largest = triple;
                }
            }
        }
        return largest;
    }
};
