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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        s1.push(root1);
        s2.push(root2);
        while (!s1.empty() && !s2.empty()) {
            if (getNum(s1) != getNum(s2)) return false;
        }
        return s1.empty() && s2.empty();
    }
    
    int getNum(stack<TreeNode*>& s) {
        while (true) {
            TreeNode* cur = s.top();
            s.pop();
            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
            if (!cur->right && !cur->left) return cur->val;
        }
    }
};