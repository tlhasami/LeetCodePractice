class Solution {
public:
    bool isValid(int n) {
        if (n == 1) return true;
        int val = 1;
        while (val < n) val *= 2;
        return val == n;
    }

    bool reorderedPowerOf2(int n) {
        if (n == 1) return true;

        vector<int> digits;
        int temp = n;
        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        sort(digits.begin(), digits.end());

        do {
            if (digits[0] == 0) continue; // skip leading zero numbers

            int num = 0;
            for (int d : digits) num = num * 10 + d;

            if (isValid(num)) return true;

        } while (next_permutation(digits.begin(), digits.end()));

        return false;
    }
};
