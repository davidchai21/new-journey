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

// recursive
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    
    void helper(Node* root, vector<int>& res) {
        if (!root) return;
        for (int i=0;i<root->children.size();i++) {
            helper(root->children[i], res);
        }
        res.push_back(root->val);
    }
};

// iterative
class Solution {
public:
    vector<int> postorder(Node* root) {
        stack<Node*> s;
        vector<int> res;
        if (!root) return res;
        s.push(root);
        while (!s.empty()) {
            Node* cur = s.top();
            s.pop();
            res.push_back(cur->val);
            for (int i=0;i<cur->children.size();i++) {
                s.push(cur->children[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};