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
        if(!head) return head;
        ListNode * curr=head,*forw = nullptr,*prev = nullptr;
        while(curr)
        {
            forw =  curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        } 
        head = prev;
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode * l3=nullptr,*temp=nullptr;
        int c=0;
        while(l1 || l2 || c)
        {
            int a=0,b=0;
            if(l1)
            {
                a = l1->val;
                l1 = l1->next;
            } 
            if(l2) 
            {
                b = l2->val;
                l2 = l2->next;
            }
            int k = a+b+c;
            c=0;
            if(k>9) c=1;
            ListNode * hs = new ListNode(k>9 ? k-10 : k);
            if(!l3) {
                l3 = temp = hs;
            }
            else {
                temp->next = hs;
                temp = temp->next;
            }
        }
        l3 = reverse(l3);
        return l3;
    }
};