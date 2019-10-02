/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        pre = NULL;
        Node* head=root;
        Node* tail=root;
        while (head->left) head = head->left;
        while (tail->right) tail = tail->right;
        helper(root);
        head->left = tail;
        tail->right = head;
        return head;
    }
private:
    Node* pre;
    void helper(Node* root) {
        if (!root) return;
        helper(root->left);
        root->left = pre;
        if (pre) pre->right = root;
        pre = root;
        helper(root->right);
    }
};