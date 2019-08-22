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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> s;
        for (int n:nums) {
            TreeNode* cur = new TreeNode(n);
            while (!s.empty() && s.top()->val<n) {
                cur->left = s.top();
                s.pop();
            }
            if (!s.empty()) s.top()->right = cur;
            s.push(cur);
        }
        while (s.size()>1) s.pop();
        return s.top();
    }
};