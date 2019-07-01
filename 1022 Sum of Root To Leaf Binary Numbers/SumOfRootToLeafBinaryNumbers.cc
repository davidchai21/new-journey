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
    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        return helper(root, 0);
    }
    
    int helper(TreeNode* root, int sum) {
        int newSum = sum*2+root->val;
        if (!root->left && !root->right) return newSum;
        return (root->left?helper(root->left, newSum):0) + (root->right?helper(root->right, newSum):0);
    }
};