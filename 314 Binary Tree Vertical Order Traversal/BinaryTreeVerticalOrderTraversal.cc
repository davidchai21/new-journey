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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (!root) return res;
        map<int, vector<int> > m;
        queue<pair<TreeNode*, int> > q;
        q.emplace(root, 0);
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int level = q.front().second;
            m[level].push_back(cur->val);
            q.pop();
            if (cur->left) q.emplace(cur->left, level-1);
            if (cur->right) q.emplace(cur->right, level+1);
        }
        for (map<int, vector<int> >::iterator it=m.begin();it!=m.end();it++) {
            res.push_back(it->second);
        }
        return res;
    }
};