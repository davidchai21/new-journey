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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        if (root == nullptr) return res;
        helper(root, res);
        return res-1;
    }
    
    int helper(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        res = max(1+left+right, res);
        return 1+max(left, right);
    }
};