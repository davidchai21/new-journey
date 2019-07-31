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
    int findTilt(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    
    int helper(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int left = helper(root->left, res);
        int right = helper(root->right, res);
        res += abs(left-right);
        return left+right+root->val;
    }
};