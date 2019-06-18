class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        record.push(x);
        if (minimum.empty()) minimum.push(x);
        else {
            minimum.push(min(x, minimum.top()));
        }
    }
    
    void pop() {
        record.pop();
        minimum.pop();
    }
    
    int top() {
        return record.top();
    }
    
    int getMin() {
        return minimum.top();
    }
private:
    stack<int> record, minimum;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */