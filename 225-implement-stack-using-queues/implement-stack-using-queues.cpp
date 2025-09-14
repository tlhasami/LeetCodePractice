class MyStack {
public:
    queue<int>values;
    MyStack() {}
    
    void push(int x) {
        values.push(x);
    }
    
    int pop() {
        queue<int> temp;
        while(values.size() > 1){
            temp.push(values.front());
            values.pop();
        }

        int toReturn = values.front(); values.pop();
        values = temp;

        return toReturn;
        
    }
    
    int top() {
        
        queue<int> temp;
        while(values.size() > 1){
            temp.push(values.front());
            values.pop();
        }

        int toReturn = values.front(); values.pop();
        temp.push( toReturn );
        values = temp;

        return toReturn;

    }
    
    bool empty() {
        return values.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */