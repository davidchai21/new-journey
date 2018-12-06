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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1 || !head) return head;
        ListNode* pre = new ListNode(0);
        ListNode* cur = pre;
        pre->next = head;
        ListNode* res = pre;
        while (1) {
            int i=0;
            for (;i<k && cur;i++) {
                cur = cur->next;
            }
            if (i==k && cur) {
                helper(pre, cur->next);
                i=0;
                while (i++<k) {
                    pre = pre->next;
                }
                cur = pre;
            } else {
                return res->next;
            }
        }
    }
    
    void helper(ListNode* front, ListNode* end) {
        ListNode* pre = front;
        ListNode* cur = front->next;
        while (cur!=end) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        front->next->next = end;
        front->next = pre;
    }
};