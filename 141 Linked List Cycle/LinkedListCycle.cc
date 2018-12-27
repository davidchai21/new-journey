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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* slow, *fast;
        slow = head;
        fast = head->next;
        while (fast && fast->next && slow!=fast) {
            slow=slow->next;
            fast=fast->next->next;
        }
        if (fast && fast==slow) return true;
        return false;
    }
};