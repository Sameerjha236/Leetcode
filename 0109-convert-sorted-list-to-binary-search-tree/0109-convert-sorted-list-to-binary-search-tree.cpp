/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode * helper(ListNode *head)
    {
        if(!head) return nullptr;
        ListNode *slow = head, *fast = head, *f = nullptr;
        while(fast && fast->next)
        {
            f = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(f)
            f->next = nullptr;
        ListNode * p = slow->next;
        slow->next = nullptr;

        TreeNode * ans = new TreeNode(slow->val);
        if(head != slow)
            ans->left = helper(head);
        ans->right = helper(p);

        return ans;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        TreeNode * root=nullptr;
        root = helper(head);
        return root;
    }
};