class Solution {
public:
    int binaryGap(int n) {

        string result = "";

        while (n > 0){
            result += (n & 1) ? "1" : "0";
            n >>= 1;
        }

        reverse(result.begin(), result.end());

        int prevIndex = -1;
        int maxGap = 0;

        for (int i = 0; i < result.size(); i++) {
            if (result[i] == '1') {

                if (prevIndex != -1) {
                    maxGap = max(maxGap, i - prevIndex);
                }

                prevIndex = i;
            }
        }

        return maxGap;
    }
};