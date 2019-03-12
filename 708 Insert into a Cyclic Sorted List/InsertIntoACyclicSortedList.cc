/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal, NULL);
            head->next = head;
            return head;
        }
        Node* small = head;
        Node* large = head;
        Node* cur = head->next;
        while (cur != head) {
            if (cur->val >= large->val) large = cur;
            cur = cur->next;
        }
        small = large->next;
        if (insertVal >= large->val || insertVal <= small->val) {
            Node* newNode = new Node(insertVal, small);
            large->next = newNode;
        } else {
            cur = small;
            while (cur->next->val < insertVal) cur = cur->next;
            Node* newNode = new Node(insertVal, cur->next);
            cur->next = newNode;
        }
        return head;
    }
};