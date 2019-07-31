/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // DFS:
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if (root == nullptr) return res;
        
        helper(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
    
    void helper(TreeNode* root, int level, vector<vector<int> >& res) {
        if (level>=res.size()) res.push_back({});
        res[level].push_back(root->val);
        if (root->left != nullptr) helper(root->left, level+1, res);
        if (root->right != nullptr) helper(root->right, level+1, res);
    }
};

// BFS:
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int> > res;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            TreeNode* cur;
            for (int i=0;i<size;i++) {
                cur = q.front();
                q.pop();
                level[i]=cur->val;
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};