class Solution {
public:
    string removeOuterParentheses(string s) {
        int curr = 0 ; string ans = "";
        for(auto& chr: s){
            if (chr == '(' && curr++>0) ans+=chr;
            else if (chr == ')' && curr-->1) ans+=chr;
        }

        return ans;
    }
};