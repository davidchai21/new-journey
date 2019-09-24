// My solution:
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        reverse(post.begin(), post.end());
        return helper(pre, 0, pre.size()-1, post, 0, post.size()-1);
    }
private:
    TreeNode* helper(vector<int>& pre, int s1, int e1, vector<int>& post, int s2, int e2) {
        if (s1>e1 || s2>e2) return NULL;
        TreeNode* root = new TreeNode(pre[s1]);
        if (s1 == e1) return root;
        int index = s2+1;
        while (index<=e2) {
            if (post[index]==pre[s1+1]) break;
            ++index;
        }
        root->left = helper(pre, s1+1,s1+1+e2-index, post, index, e2);
        root->right = helper(pre, s1+2+e2-index, e1, post, s2+1, index-1);
        return root;
    }
};

// recursive:
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if (root->val != post[postIndex]) {
            root->left = constructFromPrePost(pre, post);
        }
        if (root->val != post[postIndex]) {
            root->right = constructFromPrePost(pre, post);
        }
        ++postIndex;
        return root;
    }
private:
    int preIndex = 0;
    int postIndex = 0;
};

// iterative:
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(pre[0]);
        s.push(root);
        int index = 0;
        for (int i=1;i<pre.size();i++) {
            TreeNode* cur = new TreeNode(pre[i]);
            while (s.top()->val == post[index]) {
                ++index;
                s.pop();
            }
            if (s.top()->left == NULL) s.top()->left = cur;
            else s.top()->right = cur;
            s.push(cur);
        }
        return root;
    }
};