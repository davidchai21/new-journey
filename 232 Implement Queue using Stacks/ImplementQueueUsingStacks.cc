class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        record = stack<int>();
        helper = stack<int>();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!record.empty()) {
            helper.push(record.top());
            record.pop();
        }
        record.push(x);
        while (!helper.empty()) {
            record.push(helper.top());
            helper.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int retVal = record.top();
        record.pop();
        return retVal;
    }
    
    /** Get the front element. */
    int peek() {
        return record.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return record.empty();
    }
private:
    stack<int> record, helper;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */