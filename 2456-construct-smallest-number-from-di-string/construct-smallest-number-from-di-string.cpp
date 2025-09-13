class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char> st;
        string ans = "";
        char digit = '1';

        for (auto& chr : pattern) {
            if (chr == 'I') {
                ans += digit;
                digit++;
                while (!st.empty()) {
                    char last = st.top(); st.pop();
                    ans += last;
                }
            } else if (chr == 'D') {
                st.push(digit);
                digit++;
            }
        }

        ans += digit;
        while (!st.empty()) {
            char last = st.top(); st.pop();
            ans += last;
        }

        return ans;
    }
};
