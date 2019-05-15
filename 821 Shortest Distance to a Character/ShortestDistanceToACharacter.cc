class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> res(S.size());
        vector<int> record;
        for (int i=0;i<S.size();i++) {
            if (S[i]==C) {
                res[i]=0;
                record.push_back(i);
            }
        }
        for (int i=record[0]-1;i>=0;i--) {
            res[i]=record[0]-i;
        }
        for (int i=record.back()+1;i<S.size();i++) {
            res[i]=i-record.back();
        }
        for (int i=0;i<record.size()-1;i++) {
            int left = record[i];
            int right = record[i+1];
            for (int j=left+1;j<right;j++) {
                res[j]=min(j-left, right-j);
            }
        }
        return res;
    }
};