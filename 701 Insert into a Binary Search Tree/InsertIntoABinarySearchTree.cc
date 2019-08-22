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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return helper(root, val);
    }
    
    TreeNode* helper(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (root->val>val) root->left = helper(root->left, val);
        else root->right = helper(root->right, val);
        return root;
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root;
        TreeNode* newNode = new TreeNode(val);
        if (!root) return newNode;
        while (cur) {
            if (cur->val>val) {
                if (cur->left) {
                    cur = cur->left;
                } else {
                    cur->left = newNode;
                    break;
                }
            } else {
                if (cur->right) {
                    cur = cur->right;
                } else {
                    cur->right = newNode;
                    break;
                }
            }
        }
        return root;
    }
};