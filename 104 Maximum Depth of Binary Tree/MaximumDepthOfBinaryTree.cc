/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // BFS:
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            res++;
            int size = q.size();
            for (int i=0;i<size;i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return res;
    }
};

// DFS:
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};

// Iteration:
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, int> > s;
        int res = 0;
        s.push(make_pair(root,1));
        while (!s.empty()) {
            TreeNode* cur = s.top().first;
            int depth = s.top().second;
            s.pop();
            res = max(res, depth);
            if (cur->right) s.push(make_pair(cur->right, depth+1));
            if (cur->left) s.push(make_pair(cur->left, depth+1));
        }
        return res;
    }
};