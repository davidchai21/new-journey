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
    int distributeCoins(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        helper(root,res);
        return res;
    }
    
    pair<int, int> helper(TreeNode* root, int& res) { // #node, #val
        if (!root) return {0,0};
        pair<int,int> l = helper(root->left, res);
        pair<int,int> r = helper(root->right, res);
        res += abs(l.first-l.second);
        res += abs(r.first-r.second);
        return make_pair(l.first+r.first+1, l.second+r.second+root->val);
    }
};