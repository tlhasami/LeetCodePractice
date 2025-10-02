class MyCircularQueue {
public:
    vector<int> nums;
    int rear, front, size;

    MyCircularQueue(int k) {
        nums = vector<int>(k, -1);
        size = k;
        rear = front = -1;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        nums[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return true;        
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return nums[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return nums[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return ((rear + 1) % size) == front;
    }
};
