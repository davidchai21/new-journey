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
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
    
    int helper(TreeNode* root, int mx, int mn) {
        if (!root) return mx-mn;
        mx = max(root->val, mx);
        mn = min(root->val, mn);
        return max(helper(root->left, mx, mn), helper(root->right, mx, mn));
    }
};