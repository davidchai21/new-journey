class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string word:words) m[word]++;
        vector<pair<string,int> > record;
        for (unordered_map<string,int>::iterator it=m.begin();it!=m.end();it++) {
            record.push_back(make_pair(it->first, it->second));
        }
        sort(record.begin(), record.end(), [](pair<string,int> a, pair<string,int> b){return a.second>b.second || a.second==b.second && a.first<b.first;});
        vector<string> res;
        for (int i=0;i<k && i<record.size();i++) {
            res.push_back(record[i].first);
        }
        return res;
    }
};

// O(nlogk) time complexity
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (string word:words) m[word]++;
        priority_queue<pair<string,int>, vector<pair<string,int> >, cmp> q;
        for (unordered_map<string,int>::iterator it=m.begin();it!=m.end();it++) {
            q.push(make_pair(it->first, it->second));
            if (q.size()>k) q.pop();
        }
        int size = min(k, (int)q.size());
        vector<string> res(size);
        for (int i=size-1;i>=0;i--) {
            res[i]=q.top().first;
            q.pop();
        }
        return res;
    }
    
    struct cmp {
        bool operator()(const pair<string,int>& a, const pair<string,int>& b) {
            return a.second>b.second || a.second==b.second && a.first<b.first;
        }
    };
};