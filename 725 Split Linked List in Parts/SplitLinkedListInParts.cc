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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        if (k==1) return vector<ListNode*>{root};
        int n = count_node(root);
        int step = n/k;
        int r = n%k;
        vector<ListNode*> res(k);
        while (k) {
            int t = step;
            if (r) {
                r--;
                t++;
            }
            if (t==0) break;
            else {
                ListNode* cur = root;
                res[res.size()-k] = root;
                while (--t) {
                    cur = cur->next;
                }
                root = cur->next;
                cur->next = NULL;
            }
            k--;
        }
        return res;
    }
    
    int count_node(ListNode* root) {
        int res = 0;
        while (root) {
            res++;
            root = root->next;
        }
        return res;
    }
};