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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* rootLeft, TreeNode* rootRight) {
        if (!rootLeft && !rootRight) return true;
        if (!rootLeft && rootRight || !rootRight && rootLeft) return false;
        if (rootLeft->val != rootRight->val) return false;
        return helper(rootLeft->left, rootRight->right) && helper(rootLeft->right, rootRight->left);
    }
};

// Iterative:
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> l,r;
        l.push(root->left);
        r.push(root->right);
        while (!l.empty() && !r.empty()) {
            for (int i=0;i<l.size();i++) {
                TreeNode* curl = l.front();
                TreeNode* curr = r.front();
                l.pop();
                r.pop();
                if (!curl && !curr) continue;
                if (!curl && curr || !curr && curl) return false;
                if (curl->val != curr->val) return false;
                l.push(curl->left);
                l.push(curl->right);
                r.push(curr->right);
                r.push(curr->left);
            }
        }
        return l.size() == r.size();
    }
};