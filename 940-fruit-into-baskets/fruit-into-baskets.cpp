class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int n = fruits.size();
        int left = 0, result = 0;

        for (int right = 0; right < n; right++) {
            freq[fruits[right]]++; 

            while (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }
                left++;
            }

    
            result = max(result, right - left + 1);
        }

        return result;
    }
};
