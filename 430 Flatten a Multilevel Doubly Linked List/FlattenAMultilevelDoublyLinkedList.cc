/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return NULL;
        Node* res = head;
        while (head) {
            if (head->child) {
                Node* next = head->next;
                Node* last = helper(head->child);
                head->next = head->child;
                head->child->prev = head;
                last->next = next;
                if (next) next->prev = last;
                head->child = NULL;
            }
            head = head->next;
        }
        return res;
    }
    
    Node* helper(Node* head) {
        while (head->next) {
            head = head->next;
        }
        return head;
    }
};