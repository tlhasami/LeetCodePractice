class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;

        for (char a : s){
            if (!st.empty() && st.top() == a){
                st.pop();
            } else {
                st.push(a);
            }
        }

        string result = "";

        while (!st.empty()){
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};