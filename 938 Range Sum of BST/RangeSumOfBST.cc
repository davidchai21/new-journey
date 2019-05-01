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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        int res = 0;
        helper(root, L, R, res);
        return res;
    }
    
    void helper(TreeNode* root, int L, int R, int& res) {
        if (root) {
            if (root->val>=L && root->val<=R) {
                res+=root->val;
                helper(root->left, L, R, res);
                helper(root->right, L, R, res);
            } else if (root->val>R) {
                helper(root->left, L, R, res);
            } else {
                helper(root->right, L, R, res);
            }
        }
    }
};