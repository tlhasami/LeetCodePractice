class CustomStack {
public:
    vector<int>values;
    int size;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if (size < values.size() + 1)
             return ;
        
        values.push_back(x);
    }
    
    int pop() {
        if (values.size() == 0)
            return -1;
        
        int val = values.back();
        values.pop_back();
        return val;
    }
    
    void increment(int k, int inc) {
        // stack<int> temp ;
        
        // while (st.size() > k){
        //     temp.push(st.top());
        //     st.pop();
        // }

        // while(!st.empty()){
        //     temp.push(st.top() + val);
        //     st.pop();
        // }
        
        
        // while (!temp.empty()){
        //     st.push(temp.top());
        //     temp.pop();
        // }

        if (k >= size){

            for (auto& val : values){
                val += inc;
            }

            return ;
        }

        int n = values.size();
        for (int i = 0 ; i < n && k > 0 ; i++ , --k){
            //cout << values[i] << " " ;
            values[i] += inc;
        }

        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */