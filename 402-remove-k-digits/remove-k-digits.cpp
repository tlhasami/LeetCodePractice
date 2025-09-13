class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> st;

        for (char num : nums) {
        
            while (!st.empty() && st.top() > num && k > 0) {
                st.pop();
                k--;
            }
            st.push(num);
        }

        
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        // remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        result = result.substr(start);

        return result.empty() ? "0" : result;
    }
};
