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
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;
        unordered_map<int,int> m;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* cur = s.top();
            if (m.find(k-cur->val)!=m.end()) return true;
            s.pop();
            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
            m[cur->val]++;
        }
        return false;
    }
};