class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > res;
        vector<int> t;
        t.push_back(0);
        helper(t,res,graph);
        return res;
    }
    
    void helper(vector<int>& t, vector<vector<int> >& res, vector<vector<int> >& graph) {
        int index = t.back();
        if (index == graph.size()-1) {
            res.push_back(t);
            return;
        }
        for (int k:graph[index]) {
            t.push_back(k);
            helper(t,res,graph);
            t.pop_back();
        }
    }
};