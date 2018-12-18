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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n) return head;
        ListNode* pre = new ListNode(0);
        ListNode* left;
        ListNode* right;
        ListNode* cur = pre;
        pre->next = head;
        int i=1;
        while (i<=n) {
            if (i==m) left = cur;
            cur = cur->next;
            i++;
        }
        right = cur->next;
        helper(left, right);
        return pre->next;
    }
    void helper(ListNode* left, ListNode* right) {
        ListNode* pre = right;
        ListNode* cur = left->next;
        while (cur != right) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        left->next = pre;
    }
};