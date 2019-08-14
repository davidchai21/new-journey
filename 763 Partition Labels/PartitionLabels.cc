class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<pair<int,int> > m(26,{-1,-1});
        for (int i=0;i<S.size();i++) {
            int index = S[i]-'a';
            if (m[index].first == -1) m[index]=make_pair(i,i);
            else m[index]=make_pair(m[index].first, i);
        }
        sort(m.begin(), m.end(), [](pair<int,int> a, pair<int,int> b){return a.first<b.first || a.first==b.first && a.second<b.second;});
        vector<int> res;
        int start = 0;
        int end = -1;
        for (pair<int,int> p:m) {
            if (p.first == -1) continue;
            if (end == -1) {
                start = p.first;
                end = p.second;
            } else {
                if (end>p.first) end = max(p.second, end);
                else {
                    res.push_back(end-start+1);
                    end = p.second;
                    start = p.first;
                }
            }
        }
        if (end != -1) res.push_back(end-start+1);
        return res;
    }
};