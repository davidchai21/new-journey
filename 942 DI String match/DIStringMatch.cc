class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res(S.size()+1);
        int left = 0;
        int right = S.size();
        if (S[0]=='I') res[0]=left++;
        else res[0]=right--;
        for (int i=1;i<S.size();i++) {
            if (S[i]=='I') res[i]=left++;
            else res[i]=right--;
        }
        res[S.size()]=left;
        return res;
    }
};