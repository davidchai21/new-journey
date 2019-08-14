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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (K==0) return {target->val};
        vector<int> res;
        findVal(res,K,target);
        if (target==root) return res;
        vector<char> path,t;
        findPath(path,t,root,target);
        K-=path.size();
        for (int i=0;i<path.size();i++) {
            if (K==0) res.push_back(root->val);
            else if (K>0) {
                if (path[i]=='L') findVal(res,K-1,root->right);
                else findVal(res,K-1,root->left);
            }
            K++;
            root = path[i]=='L'?root->left:root->right;
        }
        return res;
    }
    
    void findPath(vector<char>& res, vector<char>& t, TreeNode* root, TreeNode* target) {
        if (!root || !res.empty()) return;
        if (root==target) {
            res = t;
            return;
        }
        t.push_back('L');
        findPath(res,t,root->left,target);
        t.pop_back();
        t.push_back('R');
        findPath(res,t,root->right,target);
        t.pop_back();
    }
    
    void findVal(vector<int>& res, int k, TreeNode* root) {
        if (!root || k<0) return;
        if (k==0) {
            res.push_back(root->val);
            return;
        }
        findVal(res,k-1,root->left);
        findVal(res,k-1,root->right);
    }
};