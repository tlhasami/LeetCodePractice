class CustomStack {
public:
    stack<int>st;int size;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if (size < st.size() + 1)
            return ;
        
        st.push(x);
    }
    
    int pop() {
        if (st.size() == 0)
            return -1;
        int val = st.top();st.pop();
        return val;
    }
    
    void increment(int k, int val) {
        stack<int> temp ;
        
        while (st.size() > k){
            temp.push(st.top());
            st.pop();
        }

        while(!st.empty()){
            temp.push(st.top() + val);
            st.pop();
        }
        
        
        while (!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }

        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */