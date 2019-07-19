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
    TreeNode* convertBST(TreeNode* root) {
        int pre = 0;
        helper(root, pre);
        return root;
    }
    
    void helper(TreeNode* root, int& pre) {
        if (!root) return;
        if (root->right) helper(root->right, pre);
        root->val += pre;
        pre = root->val;
        if (root->left) helper(root->left, pre);
    }
};