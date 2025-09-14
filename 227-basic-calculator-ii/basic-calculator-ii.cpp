class Solution {
public:
    int calculate(string s) {
        s += '+';
        stack<int> stk; 
        
        long long int ans = 0, curr = 0;
        char sign = '+'; 
        
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])) curr = curr*10 + (s[i]-'0'); 
            
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                
                if(sign == '+') stk.push(curr); 
            
                else if(sign == '-') stk.push(curr*(-1)); 
                
                else if(sign == '*'){
                    int num = stk.top(); stk.pop();
                    stk.push(num*curr); 
                }
                
                else if(sign == '/'){
                    int num = stk.top();stk.pop(); 
                    stk.push(num/curr); 
                }
                
                curr = 0; 
                sign = s[i]; 
            }
            
        }
        
        while(stk.size()){
            ans += stk.top(); stk.pop();
        }
            
        return ans;    
    }
};

/*

MLE
int prec(char s){
        if (s == '*' || s == '/')
            return 2;
        
        return 1;
    }
    
    int calculate(string s) {
       // Convert to postfix
        string postfix = ""; int n = s.length();
        stack<char>st;
        for (int i = 0; i < n ;i++){
            if (isdigit(s[i])){
                string num = ""; 
                while (i < n && isdigit(s[i])) {
                    num+= s[i++];
                }
                postfix = postfix + num + " ";
                i--;
            } else if (s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/'){
                while (!st.empty() && prec(st.top()) >= prec(s[i]) ){
                    postfix = postfix + st.top() + " "; st.pop();
                }
                st.push(s[i]);
            }
        }

        while (!st.empty()){
            postfix = postfix + st.top() + " "; st.pop();
        }

        // start Solving it 

        stack<int> value;
        stringstream ss(postfix);
        string token;

        while (ss >> token) {
            // If it's a number
            if (isdigit(token[0])) {
                value.push(stoi(token));
            }
            else {
                int b = value.top(); value.pop();
                int a = value.top(); value.pop();

                if (token == "+") value.push(a + b);
                else if (token == "-") value.push(a - b);
                else if (token == "*") value.push(a * b);
                else if (token == "/") value.push(a / b);
            }
        }
        return value.top();
    }
    */