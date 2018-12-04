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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* cur = new ListNode(0);
        ListNode* res = cur;
        bool flag = true;
        int index = -1;
        int value = 0;
        while (flag) {
            flag = false;
            for (int i=0;i<lists.size();i++) {
                if (lists[i]) {
                    if (!flag) {
                        flag = true;
                        index = i;
                        value = lists[i]->val;
                    } else {
                        if (lists[i]->val < value) {
                            index = i;
                            value = lists[i]->val;
                        }
                    }
                }
            }
            if (flag) {
                cur->next = new ListNode(value);
                lists[index]=lists[index]->next;
                cur = cur->next;
            }
        }
        return res->next;
    }
};