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
    TreeNode* bstToGst(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return root;
    }
    
    void helper(TreeNode* root, int& res) {
        if (!root) return;
        if (root->right) helper(root->right, res);
        res += root->val;
        root->val = res;
        if (root->left) helper(root->left, res);
    }
};