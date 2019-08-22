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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder.front());
        stack<TreeNode*> s;
        s.push(root);
        for (int i=1;i<preorder.size();i++) {
            TreeNode* t = new TreeNode(preorder[i]);
            if (preorder[i]<s.top()->val) {
                s.top()->left = t;
                s.push(t);
            } else {
                TreeNode* cur;
                while (!s.empty() && preorder[i]>s.top()->val) {
                    cur = s.top();
                    s.pop();
                }
                cur->right = t;
                s.push(t);
            }
        }
        return root;
    }
};