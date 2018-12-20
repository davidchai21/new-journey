/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        cur = head;
        int n = 0;
        while (cur) {
            n++;
            cur = cur->next;
        }
        cur = head;
        return helper(n);
    }
    
    TreeNode* helper(int n) {
        if (n<=0) return NULL;
        TreeNode* left = helper(n/2);
        TreeNode* node = new TreeNode(cur->val);
        cur = cur->next;
        TreeNode* right = helper(n-n/2-1);
        node->left = left;
        node->right = right;
        return node;
    }
private:
    ListNode* cur;
};