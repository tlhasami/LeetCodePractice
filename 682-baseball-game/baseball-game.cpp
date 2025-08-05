class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> ans;

        for (const string& opr : operations) {
            if (opr == "C") {
                ans.pop();
            }
            else if (opr == "D") {
                ans.push(ans.top() * 2);
            }
            else if (opr == "+") {
                int top1 = ans.top(); ans.pop();
                int top2 = ans.top();
                ans.push(top1);            
                ans.push(top1 + top2);     
            }
            else {
                ans.push(stoi(opr)); 
            }
        }

        int total = 0;
        while (!ans.empty()) {
            total += ans.top(); ans.pop();
        }

        return total;
    }
};
