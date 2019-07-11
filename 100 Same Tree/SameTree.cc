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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (q && p && q->val == p->val) return isSameTree(q->left, p->left) && isSameTree(q->right, p->right);
        else return false;
    }
};


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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        stack<pair<TreeNode*, TreeNode*> > s;
        s.push(make_pair(q, p));
        while (!s.empty()) {
            pair<TreeNode*, TreeNode*> cur = s.top();
            s.pop();
            if (!cur.first && !cur.second) continue;
            else if (!cur.first && cur.second || !cur.second && cur.first) return false;
            else {
                if (cur.first->val != cur.second->val) return false;
                s.push(make_pair(cur.first->right, cur.second->right));
                s.push(make_pair(cur.first->left, cur.second->left));
            }
        }
        return true;
    }
};