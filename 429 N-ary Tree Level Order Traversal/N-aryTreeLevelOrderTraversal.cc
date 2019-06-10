/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// BFS:
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            vector<int> temp(s);
            for (int i=0;i<s;i++) {
                Node* t = q.front();
                q.pop();
                temp[i]=t->val;
                for (int j=0;j<t->children.size();j++) q.push(t->children[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};

// DFS:
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > res;
        if (!root) return res;
        helper(root, 0, res);
        return res;
    }
    
    void helper(Node* root, int level, vector<vector<int> >& res) {
        if (res.size()<=level) {
            res.push_back({root->val});
        } else {
            res[level].push_back(root->val);
        }
        for (int i=0;i<root->children.size();i++) {
            if (root->children[i]) helper(root->children[i], level+1, res);
        }
    }
};