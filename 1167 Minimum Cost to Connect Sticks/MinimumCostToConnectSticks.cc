class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int> > q;
        for (int s:sticks) q.push(s);
        int res = 0;
        while (q.size()>1) {
            int a = q.top();
            q.pop();
            a += q.top();
            q.pop();
            q.push(a);
            res+=a;
        }
        return res;
    }
};