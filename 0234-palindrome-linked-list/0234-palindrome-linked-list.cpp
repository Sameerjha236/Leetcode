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
class Solution {
public:

    ListNode * reverse(ListNode * head)
    {
        if(!head) return nullptr;
        ListNode * curr=head,*forw=nullptr,*prev=nullptr;
        while(curr)
        {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode * hare=head,*tort = head;
        while(hare->next && hare->next->next)
        {
            hare = hare->next->next;
            tort = tort->next;
        }
        tort = reverse(tort);
        hare = head;
        while(hare && tort)
        {
            if(hare->val !=tort->val) return false;
            hare = hare->next;
            tort = tort->next;
        }
        return true;
    }
};