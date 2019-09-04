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
    double maximumAverageSubtree(TreeNode* root) {
        double res = -1;
        helper(root, res);
        return res;
    }
    
    pair<int, int> helper(TreeNode* root, double& res) {   // sum, #node
        if (!root) return make_pair(0,0);
        pair<int,int> l = helper(root->left, res);
        pair<int,int> r = helper(root->right, res);
        int sum = l.first + r.first + root->val;
        res = max(res, (double)sum/(l.second+r.second+1));
        return make_pair(sum, l.second+r.second+1);
    }
};