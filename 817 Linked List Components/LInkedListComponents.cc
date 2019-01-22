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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s;
        for (int& a:G) {
            s.insert(a);
        }
        int res = 0;
        bool flag = false;
        while (head) {
            if (s.find(head->val) == s.end()) {
                if (flag) flag = !flag;
            } else {
                if (!flag) {
                    flag = !flag;
                    res++;
                }
            }
            head = head->next;
        }
        return res;
    }
};