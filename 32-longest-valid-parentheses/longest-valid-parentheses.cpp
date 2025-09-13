class Solution {
public:
    int longestValidParentheses(string s) {

        if (s.length() == 0) return 0;

        stack<int> st;int size = s.length();
        vector<bool> isCorrect(size , false);

        for (auto i = 0 ; i < size ; i++){
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()){
                    isCorrect[st.top()] = true;
                    isCorrect[i] = true;
                    st.pop();
                }
            }
        }

        int result = 0 , curr = 0;
        for (auto a : isCorrect){
            //cout << a << " ";

            if (a){
                curr ++;
                result = max(result , curr);
            } else {
                curr = 0;
            }
        }// cout << endl;


        

        return result;
    }
};