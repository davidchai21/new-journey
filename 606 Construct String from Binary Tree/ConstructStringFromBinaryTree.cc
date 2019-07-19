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
    string tree2str(TreeNode* t) {
        return helper(t);
    }
    
    string helper(TreeNode* root) {
        if (!root) return "";
        if (!root->left && !root->right) return to_string(root->val);
        else if (!root->left && root->right) return to_string(root->val)+"()("+helper(root->right)+")";
        else if (!root->right && root->left) return to_string(root->val)+"("+helper(root->left)+")";
        else return to_string(root->val)+"("+helper(root->left)+")("+helper(root->right)+")";
    }
};