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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* res = odd;
        ListNode* middle = even;
        bool flag = true;
        while (head) {
            ListNode* next = head->next;
            if (flag) {
                odd->next = head;
                odd = head;
            } else {
                even->next = head;
                even = head;
            }
            flag = !flag;
            head = next;
        }
        odd->next = middle->next;
        even->next = NULL;
        return res->next;
    }
};