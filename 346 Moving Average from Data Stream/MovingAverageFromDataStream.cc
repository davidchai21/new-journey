class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        total = 0.0;
    }
    
    double next(int val) {
        while (q.size() >= size) {
            total -= q.front();
            q.pop();
        }
        q.push(val);
        total+=val;
        return total/q.size();
    }
private:
    int size = -1;
    queue<int> q;
    double total = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */