class Solution {
public:
    int maximum69Number (int num) {
        int val = num;
        vector<int> digits;
        while (val > 0){
            digits.push_back(val%10);
            val/=10;
        }
        reverse(digits.begin(),digits.end());

        int result = num, n =digits.size();
        for(int i = 0 ;i < n;i++){
            digits[i] = digits[i] == 6 ? 9 : 6;
            val = 0;
            for (auto& digit: digits){
                val = val*10 +digit;
            }
            digits[i] = digits[i] == 6 ? 9 : 6;
            result = max(result,val);
            val = 0;
        }

        return result;
        
    }
};