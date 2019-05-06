class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for (int i=0;i<A.size();i++) {
            if (A[i]%2 == 0) sum+=A[i];
        }
        vector<int> res(queries.size());
        for (int i=0;i<queries.size();i++) {
            int val = queries[i][0];
            int index = queries[i][1];
            if (A[index]%2 == 0) sum -= A[index];
            A[index] += val;
            if (A[index]%2 == 0) sum += A[index];
            res[i]=sum;
        }
        return res;
    }
};