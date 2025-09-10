class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> diff(n, 0);    // result
        stack<int> st;             // stores indices

        for (int i = n - 1; i >= 0; i--) {
            // Pop colder or equal days
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If stack not empty, top is the next warmer day
            if (!st.empty()) {
                diff[i] = st.top() - i;
            }

            // Push current day
            st.push(i);
        }
        return diff;
    }
};




/*
One Test Case Missing otherwise good to go 

        vector<int>diff; int n = temperatures.size();
        diff.reserve(n);

        for (int i = 0 ; i < n ; i++){
            bool found= false;
            for (int j = i+1 ; j < n; j++){
                if (temperatures[i] < temperatures[j]){
                    diff.push_back(j-i);
                    found =true;
                    break;
                }
            }

            if(!found) diff.push_back(0);
        }

        
        return diff;

*/