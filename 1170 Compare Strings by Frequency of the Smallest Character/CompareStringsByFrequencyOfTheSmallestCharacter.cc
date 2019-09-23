class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res(queries.size(),0);
        vector<int> dic(12,0);
        for (int i=0;i<words.size();i++) {
            ++dic[f(words[i])];
        }
        for (int i=10;i>=0;i--) {
            dic[i] += dic[i+1];
        }
        for (int i=0;i<queries.size();i++) {
            int t = f(queries[i]);
            res[i]=dic[t+1];
        }
        return res;
    }
private:
    int f(string str) {
        char a='z';
        int count = 0;
        for (char c:str) {
            if (c==a) ++count;
            else if (c<a) {
                a = c;
                count = 1;
            }
        }
        return count;
    }
};