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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        string path = to_string(root->val);
        helper(root, path, res);
        return res;
    }
    
    void helper(TreeNode* root, string str, vector<string>& res) {
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(str);
            return;
        }
        if (root->left != nullptr) helper(root->left, str+"->"+to_string(root->left->val), res);
        if (root->right != nullptr) helper(root->right, str+"->"+to_string(root->right->val), res);
    }
};