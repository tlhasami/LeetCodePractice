class Solution {
public:
    bool isEnd(stack<int>& sandwiches, queue<int>& students) {
        int topSandwich = sandwiches.top();
        queue<int> temp = students;

        while (!temp.empty()) {
            if (topSandwich == temp.front())
                return false;
            temp.pop();
        }
        return true;
    }

    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sw(sandwiches.rbegin(), sandwiches.rend());
        queue<int> st(students.begin(), students.end());

        while (!st.empty()) {
            if (st.front() == sw.top()) {
                st.pop();
                sw.pop();
            } else {
                int frontStudent = st.front(); st.pop();
                st.push(frontStudent);

                if (isEnd(sw, st)) {
                    return st.size();
                }
            }
        }

        return 0;
    }
};
