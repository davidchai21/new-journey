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
    int closestValue(TreeNode* root, double target) {
        double diff = DBL_MAX;
        int res=0;
        while (root) {
            if (root->val==target) return root->val;
            double _diff = abs(target-root->val);
            if (diff>_diff) {
                diff = _diff;
                res = root->val;
            }
            if (root->val>target) root = root->left;
            else root = root->right;
        }
        return res;
    }
};