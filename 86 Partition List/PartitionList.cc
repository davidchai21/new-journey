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
    ListNode* partition(ListNode* head, int x) {
        ListNode* fast_pre = new ListNode(0);
        ListNode* slow_pre = new ListNode(0);
        ListNode* fast = fast_pre;
        ListNode* res = slow_pre;
        while (head) {
            if (head->val < x) {
                slow_pre->next = head;
                slow_pre = head;
            } else {
                fast_pre->next = head;
                fast_pre = head;
            }
            head = head->next;
        }
        fast_pre->next = NULL;
        slow_pre->next = fast->next;
        return res->next;
    }
};