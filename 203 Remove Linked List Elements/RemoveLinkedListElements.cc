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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        head = pre;
        while (head->next) {
            if (head->next->val == val) {
                ListNode* node = head->next;
                head->next = head->next->next;
                delete node;
            } else {
                head = head->next;
            }
        }
        return pre->next;
    }
};