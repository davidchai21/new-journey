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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<pair<int,int> > s;
        while (head) {
            while (!s.empty() && s.top().first<head->val) {
                res[s.top().second] = head->val;
                s.pop();
            }
            s.push(make_pair(head->val, res.size()));
            res.push_back(0);
            head = head->next;
        }
        return res;
    }
};