class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for ( auto& log : logs){
            if ("../" == log && !st.empty()){
                st.pop();
            } else if ("./" == log){
                continue;
            } else if (isalpha(log[0]) || isdigit(log[0])) {
                st.push(log);
            }
        }

        return st.size();
    }
};