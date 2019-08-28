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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (!head) return head;
        unordered_map<int,ListNode*> m;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        m[0]=dummy;
        int sum = 0;
        while (head->next) {
            sum += head->next->val;
            if (m.find(sum)!=m.end()) {
                m[sum]->next = head->next->next;
                head = m[sum];
                continue;
            }
            m[sum]=head->next;
            head = head->next;
        }
        return dummy->next;
    }
};