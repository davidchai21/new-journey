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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root || !root->left && !root->right) return 0;
        int res = 0;
        helper(root, 'L', res);
        return res;
    }
    
    void helper(TreeNode* root, char branch, int& res) {
        if (!root->left && !root->right) {
            if (branch == 'L') res += root->val;
            return;
        }
        if (root->left) helper(root->left, 'L', res);
        if (root->right) helper(root->right, 'R', res);
    }
};