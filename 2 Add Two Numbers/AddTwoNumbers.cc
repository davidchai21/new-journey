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
        ListNode* res=new ListNode(0);
        ListNode* cur=res;
        bool flag=false;
        while (l1 || l2 || flag) {
            int sum=flag;
            if (l1) {
                sum+=l1->val;
                l1=l1->next;
            }
            if (l2) {
                sum+=l2->val;
                l2=l2->next;
            }
            ListNode* t=new ListNode(sum%10);
            flag=sum/10;
            cur->next=t;
            cur=t;
        }
        return res->next;
    }
};