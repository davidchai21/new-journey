class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int first = -1;
        int second = -1;
        int res = -1;
        for (int i=0;i<seats.size();i++) {
            if (seats[i]) {
                if (first == -1) {
                    first = i;
                    res = i;
                } else if (second == -1) {
                    second = i;
                    res = max(res, (second-first)/2);
                } else {
                    first = second;
                    second = i;
                    res = max(res, (second-first)/2);
                }
            }
        }
        if (second!=-1) res = max(res, (int)(seats.size()-1-second));
        else res = max(res, (int)(seats.size()-1-first));
        return res;
    }
};