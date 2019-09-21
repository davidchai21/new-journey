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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> s(to_delete.begin(), to_delete.end());
        helper(res, root, s, true);
        return res;
    }
private:
    TreeNode* helper(vector<TreeNode*>& res, TreeNode* root, unordered_set<int>& s, bool head) {
        if (!root) return NULL;
        if (head) {
            if (s.find(root->val)==s.end()) {
                res.push_back(root);
                root->left = helper(res, root->left, s, false);
                root->right = helper(res, root->right, s, false);
            } else {
                helper(res, root->left, s, true);
                helper(res, root->right, s, true);
                root->left = NULL;
                root->right = NULL;
            }
        } else {
            if (s.find(root->val)==s.end()) {
                root->left = helper(res, root->left, s, false);
                root->right = helper(res, root->right, s, false);
                return root;
            } else {
                helper(res, root->left, s, true);
                helper(res, root->right, s, true);
                root->left = NULL;
                root->right = NULL;
            }
        }
        return NULL;
    }
};