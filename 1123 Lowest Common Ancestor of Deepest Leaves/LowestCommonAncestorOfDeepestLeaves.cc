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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).second;
    }
    
    pair<int, TreeNode*> helper(TreeNode* root) {
        if (!root) return make_pair(0,nullptr);
        pair<int,TreeNode*> l = helper(root->left);
        pair<int,TreeNode*> r = helper(root->right);
        if (l.first>r.first) return make_pair(l.first+1, l.second);
        if (l.first<r.first) return make_pair(r.first+1, r.second);
        return make_pair(l.first+1, root);
    }
};