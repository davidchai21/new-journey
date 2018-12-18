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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* cur = pre;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                ListNode* tail = cur->next->next;
                while (tail && tail->val == cur->next->val) {
                    tail = tail->next;
                }
                cur->next = tail;
            }
            else {
                cur = cur->next;
            }
        }
        return pre->next;
    }
};