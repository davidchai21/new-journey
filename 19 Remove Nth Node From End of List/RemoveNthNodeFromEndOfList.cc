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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0);
        res->next = head;
        ListNode* cur = head;
        ListNode* pre = res;
        while (cur) {
            if (n) n--;
            else {
                pre = pre->next;
            }
            cur = cur->next;
        }
        pre->next = pre->next->next;
        return res->next;
    }
};