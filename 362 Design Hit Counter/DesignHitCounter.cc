class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        while (!q.empty()) q.pop();
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        q.push(timestamp);
        while (q.front()+duration<=timestamp) q.pop();
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!q.empty() && q.front()+duration<=timestamp) q.pop();
        return q.size();
    }
private:
    queue<int> q;
    const int duration = 300;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */