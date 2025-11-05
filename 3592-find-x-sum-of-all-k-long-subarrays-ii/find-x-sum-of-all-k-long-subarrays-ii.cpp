class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> answer;
        answer.reserve(n - k + 1);

        unordered_map<long long, int> cnt;
        // comparator: higher freq first; if tie, higher value first
        auto cmp = [](const pair<int, long long>& a, const pair<int, long long>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        };
        // multiset with custom comparator so largest (freq,value) at end
        multiset<pair<int, long long>, decltype(cmp)> L(cmp), R(cmp);

        long long sumL = 0;

        auto add = [&](long long v) {
            int oldF = cnt[v]++;
            int newF = oldF + 1;
            if (oldF > 0) {
                // remove old pair
                pair<int, long long> oldPair = {oldF, v};
                if (L.find(oldPair) != L.end()) {
                    L.erase(L.find(oldPair));
                    sumL -= oldF * v;
                } else {
                    R.erase(R.find(oldPair));
                }
            }
            // insert new pair
            pair<int, long long> newPair = {newF, v};
            R.insert(newPair);
        };

        auto remove = [&](long long v) {
            int oldF = cnt[v]--;
            int newF = oldF - 1;
            // remove old pair
            pair<int, long long> oldPair = {oldF, v};
            if (L.find(oldPair) != L.end()) {
                L.erase(L.find(oldPair));
                sumL -= oldF * v;
            } else {
                R.erase(R.find(oldPair));
            }
            if (newF > 0) {
                // insert new pair
                pair<int, long long> newPair = {newF, v};
                R.insert(newPair);
            } else {
                cnt.erase(v);
            }
        };

        auto rebalance = [&]() {
            // Ensure L has size ≤ x, and top elements
            while ((int)L.size() < x && !R.empty()) {
                auto it = prev(R.end());
                auto p = *it;
                R.erase(it);
                L.insert(p);
                sumL += 1LL * p.first * p.second;
            }
            while ((int)L.size() > x) {
                auto it = L.begin();
                auto p = *it;
                sumL -= 1LL * p.first * p.second;
                L.erase(it);
                R.insert(p);
            }
            // If largest in R is “bigger” than smallest in L, swap
            while (!R.empty() && !L.empty()) {
                auto itR = prev(R.end());
                auto itL = L.begin();
                if (cmp(*itL, *itR)) {
                    // *itR > *itL
                    auto pR = *itR;
                    auto pL = *itL;
                    // move
                    sumL -= 1LL * pL.first * pL.second;
                    sumL += 1LL * pR.first * pR.second;
                    R.erase(itR);
                    L.erase(itL);
                    L.insert(pR);
                    R.insert(pL);
                } else break;
            }
        };

        // build initial window
        for (int i = 0; i < k; i++) {
            add(nums[i]);
        }
        rebalance();
        answer.push_back(sumL);

        // slide windows
        for (int i = k; i < n; i++) {
            add(nums[i]);
            remove(nums[i - k]);
            rebalance();
            answer.push_back(sumL);
        }

        return answer;
    }
};
