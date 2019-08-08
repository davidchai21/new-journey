class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        while (!s.empty()) s.pop();
    }
    
    void push(int x) {
        if (s.empty()) s.push(make_pair(x,x));
        else {
            int bigVal = max(s.top().second, x);
            s.push(make_pair(x, bigVal));
        }
    }
    
    int pop() {
        int res = s.top().first;
        s.pop();
        return res;
    }
    
    int top() {
        return s.top().first;
    }
    
    int peekMax() {
        return s.top().second;
    }
    
    int popMax() {
        int maxVal = s.top().second;
        while (s.top().first != maxVal) {
            h.push(s.top().first);
            s.pop();
        }
        s.pop();
        while (!h.empty()) {
            int x = h.top();
            if (s.empty()) s.push(make_pair(x, x));
            else {
                int nextmax = max(s.top().second, h.top());
                s.push(make_pair(x, nextmax));
            }
            h.pop();
        }
        return maxVal;
    }
private:
    stack<pair<int,int> > s;
    stack<int> h;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */