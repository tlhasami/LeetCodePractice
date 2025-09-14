class Solution {
public:

int calculate(string s) {
    long runningSum = 0; 
    int sign = 1; 
    stack<int> stk;  

    for (int i = 0; i < s.size(); i++) {
        char current = s[i];

        if (isdigit(current)) {
            long num = 0;
            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            runningSum += sign * num;
            i--; // adjust for the for-loop increment
        }
        else if (current == '+') {
            sign = 1; 
        }
        else if (current == '-') {
            sign = -1; 
        }
        else if (current == '(') {
            stk.push(runningSum);
            stk.push(sign);
            runningSum = 0;
            sign = 1; 
        }
        else if (current == ')') {
            int prevSign = stk.top(); stk.pop();
            int prevSum = stk.top(); stk.pop();
            runningSum = prevSum + prevSign * runningSum;
        }
        // ignore spaces
    }

    return runningSum;
}

};