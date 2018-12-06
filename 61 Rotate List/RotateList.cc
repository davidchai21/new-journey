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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k==0 || !head) return head;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        int l = 0;
        ListNode* tail = pre;
        while (tail->next) {
            l++;
            tail = tail->next;
        }
        if (k%l == 0) return head;
        tail->next = head;
        tail = pre;
        int t = l-k%l;
        while (t--) {
            tail=tail->next;
        }
        ListNode* res = tail->next;
        tail->next = NULL;
        return res;
    }
};