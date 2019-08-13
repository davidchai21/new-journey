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
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        if (!root) return 0;
        dfs(root, sum, res);
        return res;
    }
    
    void dfs(TreeNode* root, int sum, int& res) {
        if (!root) return;
        helper(root, 0, sum, res);
        dfs(root->left, sum, res);
        dfs(root->right, sum, res);
    }
    
    void helper(TreeNode* root, int sum, int target, int& res) {
        if (!root) return;
        if (root->val+sum==target) res++;
        helper(root->left, sum+root->val, target, res);
        helper(root->right, sum+root->val, target, res);
    }
};