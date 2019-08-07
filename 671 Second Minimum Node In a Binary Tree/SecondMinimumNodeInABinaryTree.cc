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
    int findSecondMinimumValue(TreeNode* root) {
        int res = -1;
        if (!root) return res;
        int base = root->val;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            if (cur->val != base) {
                if (res == -1) res = cur->val;
                else res = min(cur->val, res);
            }
            if (cur->left) {
                s.push(cur->right);
                s.push(cur->left);
            }
        }
        return res;
    }
};