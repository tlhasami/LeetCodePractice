class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> st_1;
        stack <char> st_2;

        for (auto& val : s){
            if (val == '#' && !st_1.empty()){
                st_1.pop();
            } if (isalpha(val)){
                st_1.push(val);
            }
        }

        for (auto& val : t){
            if (val == '#' && !st_2.empty()){
                st_2.pop();
            } else if (isalpha(val)){
                st_2.push(val);
            }
        }

        int n = st_1.size() , m = st_2.size();
        if (n != m)
            return false;

        while (!st_1.empty() && !st_2.empty()){
            if (st_1.top() != st_2.top())
                return false;
            st_1.pop();
            st_2.pop();
        }
        
        return true;
    }
};