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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if (m.find(N)!=m.end()) return m[N];
        if (N==1) {
            res.push_back(new TreeNode(0));
        } else if (N%2) {
            for (int i=1;i<N;i+=2) {
                int l=i;
                int r=N-1-i;
                for (TreeNode* leftTree: allPossibleFBT(l)) {
                    for (TreeNode* rightTree: allPossibleFBT(r)) {
                        TreeNode* root = new TreeNode(0);
                        root->left = clone(leftTree);
                        root->right = clone(rightTree);
                        res.push_back(root);
                    }
                }
            }
        }
        m[N]=res;
        return res;
    }
private:
    unordered_map<int, vector<TreeNode*> > m;
    TreeNode* clone(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* res = new TreeNode(0);
        res->left = clone(root->left);
        res->right = clone(root->right);
        return res;
    }
};