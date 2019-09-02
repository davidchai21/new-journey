class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res(k);
        unordered_map<int,int> m;
        for (int n:nums) m[n]++;
        priority_queue<pair<int,int>, vector<pair<int,int> >, cmp> q;
        for (unordered_map<int,int>::iterator it = m.begin();it!=m.end();it++) {
            q.push(make_pair(it->first, it->second));
            if (q.size()>k) q.pop();
        }
        for (int i=0;i<k;i++) {
            res[i]=q.top().first;
            q.pop();
        }
        return res;
    }
private:
    struct cmp {
        bool operator() (const pair<int,int>& a, const pair<int,int>& b) { // <int, freq>
            return a.second>b.second;
        }
    };
};