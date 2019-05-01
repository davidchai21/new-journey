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


// iterative
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return vector<int>();
        stack<Node*> s;
        s.push(root);
        vector<int> res;
        while (!s.empty()) {
            Node* cur = s.top();
            s.pop();
            res.push_back(cur->val);
            for (int i=cur->children.size()-1;i>=0;i--) {
                s.push(cur->children[i]);
            }
        }
        return res;
    }
};


// recursive
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    
    void helper(Node* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        for (int i=0;i<root->children.size();i++) {
            helper(root->children[i], res);
        }
    }
};