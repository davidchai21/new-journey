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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            TreeNode* cur = s.top();
            s.pop();
            res.push_back(cur->val);
            root = cur->right;
        }
        return res;
    }
};

// Recursive:
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(res, root);
        return res;
    }
private:
    void helper(vector<int>& res, TreeNode* root) {
        if (!root) return;
        helper(res, root->left);
        res.push_back(root->val);
        helper(res, root->right);
    }
};

// Morris Algorithm:
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        TreeNode* pre;
        while (cur) {
            if (!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right) {
                    pre = pre->right;
                }
                pre->right = cur;
                pre = cur->left;
                cur->left = NULL;
                cur = pre;
            }
        }
        return res;
    }
};