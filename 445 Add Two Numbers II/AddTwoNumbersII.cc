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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        int flag = 0;
        ListNode* res = new ListNode(0);
        while (l1 || l2 || flag) {
            if (l1) {
                flag += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                flag += l2->val;
                l2 = l2->next;
            }
            ListNode* now = new ListNode(flag%10);
            flag /= 10;
            now->next = res->next;
            res->next = now;
        }
        return res->next;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* pre = NULL;
        while (head) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};