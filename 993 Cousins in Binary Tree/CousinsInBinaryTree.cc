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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root || root->val == x || root->val == y) return false;
        pair<int, TreeNode*> px = helper(root, x);
        pair<int, TreeNode*> py = helper(root, y);
        return px.first == py.first && px.second != py.second;
    }
    
    pair<int, TreeNode*> helper(TreeNode* root, int x) {
        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i=0;i<n;i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) {
                    if (cur->left->val == x) return make_pair(depth, cur);
                    q.push(cur->left);
                }
                if (cur->right) {
                    if (cur->right->val == x) return make_pair(depth, cur);
                    q.push(cur->right);
                }
            }
            depth++;
        }
        auto res = make_pair(-1, nullptr);
        return res;
    }
};