class Solution {
public:

    int numSub(string s) {
        long long count = 0, total = 0;
        const long long MOD = 1'000'007;

        for (char c : s) {
            if (c == '1') {
                count++;
            } else {
                total += (count * (count + 1)) / 2;
                count = 0;
            }
        }

        if (count > 0)
            total += (count * (count + 1)) / 2;

        
        return total%1000000007LL;
    }
};
