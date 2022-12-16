class MyQueue {
public:
    int arr[1000];
    int start = 0;
    int index = -1;
    MyQueue() {
        
    }
    
    void push(int x) {
        ++index;
        arr[index] = x;
    }
    
    int pop() {
        return arr[start++];
    }
    
    int peek() {
        return arr[start];
    }
    
    bool empty() {
        if(index == start-1) return true;
        else return false;
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