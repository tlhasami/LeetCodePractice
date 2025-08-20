class Solution {
public:
    string removeStars(string s) {
        stack<char>st;

        for(auto& alpha : s){
            if (alpha == '*' && !st.empty()){
                st.pop();
            } else {
                st.push(alpha);
            }
        }

        string result;
        while (!st.empty()){
            result += st.top();
            st.pop();
        }

        reverse(result.begin() , result.end());
        return result;
    }
};