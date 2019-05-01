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
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        return check(root->left, val) && check(root->right, val);
    }
    
    bool check(TreeNode* root, int val) {
        if (!root) return true;
        if (root->val != val) return false;
        return check(root->left, val) && check(root->right, val);
    }
};