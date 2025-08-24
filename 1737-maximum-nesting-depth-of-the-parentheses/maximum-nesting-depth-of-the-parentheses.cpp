class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, result = 0;

        for (auto& val : s) {
            if (val == '(') {
                depth++;
                result = max(result, depth);
            } else if (val == ')') {
                depth--;
            }
        }

        return result;
    }
};
