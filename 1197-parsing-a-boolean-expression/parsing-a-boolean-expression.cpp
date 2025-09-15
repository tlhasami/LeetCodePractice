class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;

        for (char val : expression){
            if (val == '&' || val == '|' || val == '(' 
             || val == 't' || val == 'f' || val == '!'
             || val == ',') 
                    st.push(val);
            
            else if (val == ')') {
                vector<bool> values;
                
                while (!st.empty() && (st.top() == 't' || st.top() == 'f' || st.top() == ',')){
                    if (st.top() == 't')
                        values.push_back(true);
                    else if (st.top() == 'f')
                        values.push_back(false);
                    st.pop();
                }

                st.pop(); // poping (
                
                char opr = st.top();
                st.pop(); // removing to opr;
                if (opr == '!')
                    st.push((values[0] ? 'f' : 't')); // invert this
                else if (opr == '&'){
                    int first = values[0] , n = values.size();

                    for (int i = 1 ; i < n ; i++){
                        first &= values[i];
                    }

                    st.push((first? 't' : 'f'));
                } else if (opr == '|'){
                    int first = values[0] , n = values.size();
                    for (int i = 1 ; i < n ; i++){
                        first |= values[i];
                    }

                    st.push((first? 't' : 'f'));
                }

            }

        }


        return (st.top() == 't') ?  true:false;
    }
};