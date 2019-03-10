/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* left = newHead;
        ListNode* right = head;
        while (right) {
            while (right && right->val == 9) right = right->next;
            if (right) {
                left = right;
                right = right->next;
            }
        }
        left->val += 1;
        left = left->next;
        while (left != right) {
            left->val = 0;
            left = left->next;
        }
        return newHead->val == 1?newHead:head;
    }
};