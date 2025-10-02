class MyCircularDeque {
    vector<int> nums;
    int front;
    int rear;
    int size;
public:

    MyCircularDeque(int k) {
        front = rear = -1;
        nums = vector<int>(k , -1);
        size = k ;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;

        if (isEmpty()){
            front = rear = 0;
        } else {
            front = (front-1 + size) % size;
        }

        nums[front] = value;

        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) 
            return false;

        if (isEmpty()){
            front = rear = 0;
        } else {
            rear = (rear+1) % size;
        }

        nums[rear] = value;

        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front+1)%size;
        }

        return true;
        
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;

        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear-1 + size)%size;
        }

        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return nums[front];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return nums[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return ((rear+1)%size) == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */