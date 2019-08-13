class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        unordered_map<int,vector<int> > m;
        for (vector<int> path:paths) {
            int i,j;
            tie(i,j) = minmax(path[0]-1, path[1]-1);
            m[j].push_back(i);
        }
        vector<int> res(N,1);
        for (int i=1;i<N;i++) {
            vector<int> adj = m[i];
            bitset<4> plant("1111");
            for (int j=0;j<adj.size();j++) {
                int bit = res[adj[j]]-1;
                plant[bit]=0;
            }
            for (int j=0;j<4;j++) {
                if (plant[j]==1) {
                    res[i]=j+1;
                    break;
                }
            }
        }
        return res;
    }
};