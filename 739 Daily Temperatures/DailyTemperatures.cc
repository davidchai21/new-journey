class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(),0);
        stack<int> s;
        for (int i=0;i<T.size();++i) {
            if (s.empty() || T[s.top()]>=T[i]) s.push(i);
            else {
                res[s.top()] = i-s.top();
                s.pop();
                --i;
            }
        }
        return res;
    }
};