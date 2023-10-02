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

    void rev(ListNode * curr, ListNode * prev, ListNode * x)
    {
        ListNode * tp = curr;
        while(curr != x)
        {
            ListNode * forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        tp->next = x;
    }

public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int k = 2;
        ListNode *prev = head, *curr=head->next;
        while(curr)
        {
            ListNode * x =  curr, * forw = nullptr;
            ListNode * tmp = curr;
            int n=0;
            while(tmp && n!=k)
            {
                x = tmp;
                tmp = tmp->next;
                n++;
            }
            if(x) forw = x->next;
            
            if(n%2 == 0)
            {
                prev->next = x;
                rev(curr,prev,x->next);
                prev = curr;
            } 
            else
                prev = x;
            curr = forw;
            k++;
        }
        return head;
    }
};