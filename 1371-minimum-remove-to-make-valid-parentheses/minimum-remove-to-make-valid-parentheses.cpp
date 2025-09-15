class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        int n = s.length();
        for (int i = 0 ; i < n ; i++){
            if (s[i] == '('){
                st.push({s[i] , i});
            } else if (s[i] == ')' && st.empty()){
                s[i] = '*';
            } else if (s[i] == ')' && !st.empty() && st.top().first == '('){
                st.pop();
            } else if (s[i] == ')' && !st.empty() && st.top().first == ')'){
                s[i] = '*';
            } else {
                // in letter case
                continue;
            }
        }

        while(!st.empty()){
            auto& [val,idx] = st.top();
            st.pop();

            s[idx] = '*';
        }

        string result;
        for (char& b : s){
            if (b == '*')
                continue;
            
            result += b;
        }

        return result;
    }
};