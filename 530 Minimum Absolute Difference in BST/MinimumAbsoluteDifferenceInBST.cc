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
    int getMinimumDifference(TreeNode* root) {
        int pre = -1;
        int res = INT_MAX;
        helper(root, pre, res);
        return res;
    }
    
    void helper(TreeNode* root, int& pre, int& res) {
        if (!root) return;
        helper(root->left, pre, res);
        if (pre == -1) pre = root->val;
        else {
            res = min(res, root->val-pre);
            pre = root->val;
        }
        helper(root->right, pre, res);
    }
};