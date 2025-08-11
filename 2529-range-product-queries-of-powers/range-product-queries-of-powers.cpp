class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> powers; 
        int bit = 0;

        int temp = n;
        while (temp > 0) {
            if (temp & 1)
                powers.push_back(1 << bit);
            bit++;
            temp >>= 1;
        }

        int size = queries.size();
        vector<int> result(size, 1);

        int idx = 0;
        for (auto &query : queries) {
            for (int i = query[0]; i <= query[1]; i++) {
                result[idx] = (1LL * result[idx] * powers[i]) % MOD;
            }
            idx++;
        }

        return result;
    }
};
