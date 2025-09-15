class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        int value = 1;
        vector<string> result;
        stack<int> st;
        for (int num : target){
            if (value == num){
                st.push(value++); result.push_back("Push");
            } else {
                while (value!=num){
                    st.push(value++); st.pop();
                    result.push_back("Push");
                    result.push_back("Pop");
                }
                st.push(value++); result.push_back("Push");
            }
        }

        return result;
    }
};