class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k%2==0) return -1;
        for (int r = 0, N = 1; N <= k; ++N)
            if ((r = (r * 10 + 1) % k) == 0)
                return N;
        return -1;

    }
};