class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res=0;
        stack<int> score;
        for (string a:ops) {
            if (a=="+") {
                int first = score.top();
                score.pop();
                int second = score.top();
                score.push(first);
                score.push(first+second);
                res+=first+second;
            } else if (a=="C") {
                res-=score.top();
                score.pop();
            } else if (a=="D") {
                int doubled = score.top()*2;
                res+=doubled;
                score.push(doubled);
            } else {
                score.push(stoi(a));
                res+=score.top();
            }
        }
        return res;
    }
};