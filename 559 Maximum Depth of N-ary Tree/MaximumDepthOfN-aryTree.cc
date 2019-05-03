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
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int maxD = 0;
        for (int i=0;i<root->children.size();i++) {
            maxD = max(maxD, maxDepth(root->children[i]));
        }
        return maxD+1;
    }
};

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
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        queue<Node*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            res++;
            int size = q.size();
            for (int i=0;i<size;i++) {
                Node* cur = q.front();
                q.pop();
                for (int j=0;j<cur->children.size();j++) {
                    if (cur->children[j]) q.push(cur->children[j]);
                }
            }
        }
        return res;
    }
};