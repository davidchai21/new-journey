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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int res = 1;
        dfs(root, res);
        return res-1;
    }
    
    void dfs(TreeNode* root, int& res) {
        if (!root) return;
        res = max(res, helper(root->left, root->val)+helper(root->right, root->val)+1);
        dfs(root->left, res);
        dfs(root->right, res);
    }
    
    int helper(TreeNode* root, int val) {
        if (!root || root->val != val) return 0;
        return max(helper(root->left, val), helper(root->right, val))+1;
    }
};