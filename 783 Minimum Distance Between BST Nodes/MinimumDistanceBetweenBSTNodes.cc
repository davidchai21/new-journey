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
    int minDiffInBST(TreeNode* root) {
        int pre = 0;
        int res = -1;
        helper(root, pre, res);
        return res;
    }
    
    void helper(TreeNode* root, int& pre, int& res) {
        if (!root) return;
        helper(root->left, pre, res);
        if (res == -1) {
            pre = root->val;
            res = 0;
        } else {
            res = res==0?root->val-pre:min(res, root->val-pre);
            pre = root->val;
        }
        helper(root->right, pre, res);
    }
};