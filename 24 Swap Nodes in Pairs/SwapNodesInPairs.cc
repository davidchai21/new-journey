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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* res = pre;
        while (pre->next && pre->next->next) {
            ListNode* cur = pre->next;
            pre->next = cur->next;
            pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = cur;
        }
        return res->next;
    }
};