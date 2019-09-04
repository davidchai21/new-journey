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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* B = new TreeNode(val);
        if (!root) return B;
        TreeNode* copy = deepcopy(root);
        TreeNode* res = copy;
        if (copy->val<val) {
            B->left = copy;
            res = B;
        } else {
            while (copy) {
                if (!copy->right || copy->right->val<val) {
                    B->left = copy->right;
                    copy->right = B;
                    break;
                }
                copy = copy->right;
            }
        }
        return res;
    }
    
    TreeNode* deepcopy(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* node = new TreeNode(root->val);
        node->left = deepcopy(root->left);
        node->right = deepcopy(root->right);
        return node;
    }
};