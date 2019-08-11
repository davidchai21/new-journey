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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return minDepth(root->right)+1;
        if (!root->right) return minDepth(root->left)+1;
        return min(minDepth(root->left), minDepth(root->right))+1;
    }
};

// BFS:
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 1;
        while (!q.empty()) {
            int k=q.size();
            for (int i=0;i<k;i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left==nullptr && cur->right==nullptr) return res;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res++;
        }
        return res;
    }
};