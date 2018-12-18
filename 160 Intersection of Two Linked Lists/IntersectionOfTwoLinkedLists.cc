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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        int hit = 0;
        while (hit < 2) {
            if (l1 == l2) return l1;
            if (l1) {
                l1 = l1->next;
            } else {
                hit++;
                l1 = headB;
            }
            if (l2) {
                l2 = l2->next;
            } else {
                l2 = headA;
            }
        }
        return NULL;
    }
};