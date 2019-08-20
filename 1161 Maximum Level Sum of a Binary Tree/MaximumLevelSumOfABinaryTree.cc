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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int res = 1;
        int sum = root->val;
        while (!q.empty()) {
            int n=q.size();
            int _sum = 0;
            for (int i=0;i<n;i++) {
                _sum+=q.front()->val;
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            if (_sum>sum) {
                sum = _sum;
                res = level;
            }
            level++;
        }
        return res;
    }
};