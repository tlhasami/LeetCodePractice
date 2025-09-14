class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (char a : s){
            if (isdigit(a) || a == '[' || isalpha(a)){
                string toPush = "";
                toPush += a;
                st.push(toPush);
            } else if (!st.empty() && a == ']'){
                string construct = "";

                while (!st.empty() && st.top() != "[" ){
                    construct = st.top() + construct;
                    st.pop();
                }

                st.pop(); // remove [
                //construct the number  
                int multiply = 0, curr = 1;

                while (!st.empty() && st.top() >= "0" && st.top() <= "9" ){
                    int val = stoi(st.top()); st.pop();
                    multiply = multiply + val*curr;
                    
                    curr *= 10;
                }

                string constructed = "";
                while (multiply >= 1){
                    constructed += construct;
                    multiply--;
                }

                st.push(constructed);
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