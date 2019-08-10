class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> record(3);
        vector<bool> visited(3,false);
        for (int n:nums) {
            int candidate = n;
            for (int i=0;i<3;i++) {
                if (!visited[i]) {
                    visited[i]=true;
                    record[i]=candidate;
                    break;
                } else {
                    if (record[i]<candidate) {
                        int t = record[i];
                        record[i]=candidate;
                        candidate = t;
                    } else if (record[i]==candidate) break;
                }
            }
        }
        return visited[2]?record.back():record[0];
    }
};