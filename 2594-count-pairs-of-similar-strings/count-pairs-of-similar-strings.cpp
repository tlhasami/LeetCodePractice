class Solution {
public:

    bool isSame(unordered_set<char>& s1, unordered_set<char>& s2) {
        return s1 == s2;
    }

    int similarPairs(vector<string>& words) {
        int n = words.size();
        vector<unordered_set<char>> freq(n);

        for (int i = 0; i < n; i++) {
            for (char ch : words[i]) {
                freq[i].insert(ch);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSame(freq[i], freq[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};
