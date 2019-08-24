/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int> > res;
        helper(root, res);
        return res;
    }
    
    int helper(TreeNode* root, vector<vector<int> >& res) {
        if (!root) return 0;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        int level = max(left, right);
        if (res.size()<=level) res.push_back({});
        res[level].push_back(root->val);
        return level+1;
    }
};