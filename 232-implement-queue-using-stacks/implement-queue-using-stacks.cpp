class MyQueue {
public:
    stack<int> values;
    MyQueue() {}
    
    void push(int x) {
        values.push(x);
    }
    
    int pop() {
        stack<int>temp;

        while(!values.empty()){
            temp.push(values.top());
            values.pop();
        }

        int toReturn = temp.top();
        temp.pop();

        while(!temp.empty()){
            values.push(temp.top());
            temp.pop();
        }

        return toReturn;
        
    }
    
    int peek() {
        stack<int>temp;

        while(!values.empty()){
            temp.push(values.top());
            values.pop();
        }

        int toReturn = temp.top();

        while(!temp.empty()){
            values.push(temp.top());
            temp.pop();
        }

        return toReturn;
    }
    
    bool empty() {
        return values.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */