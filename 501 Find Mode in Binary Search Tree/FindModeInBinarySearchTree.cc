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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        int len = 0;
        int curlen = 0;
        int curval = 0;
        helper(root, res, len, curlen, curval);
        if (curlen>len) {
            res.clear();
            res.push_back(curval);
        } else if (curlen == len) res.push_back(curval);
        return res;
    }
    
    void helper(TreeNode* root, vector<int>& res, int& len, int& curlen, int& curval) {
        if (!root) return;
        helper(root->left, res, len, curlen, curval);
        if (curlen == 0) {
            curlen = 1;
            curval = root->val;
        } else {
            if (root->val == curval) curlen++;
            else {
                if (len<curlen) {
                    len = curlen;
                    res.clear();
                    res.push_back(curval);
                } else if (len == curlen) {
                    res.push_back(curval);
                }
                curval = root->val;
                curlen = 1;
            }
        }
        helper(root->right, res, len, curlen, curval);
    }
};