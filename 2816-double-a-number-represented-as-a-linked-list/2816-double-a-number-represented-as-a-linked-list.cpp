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
    
    ListNode * rev(ListNode * head)
    {
        ListNode * prev = nullptr, *curr = head;
        while(curr)
        {
            ListNode * forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        ListNode * temp = head = rev(head);
        while(temp)
        {
            int k = temp->val*2 + carry;
            // cout<<temp->val<<" "<<k<<" ";
            if(k>=10)
            {
                temp->val = k % 10;
                carry = 1;
            }
            else
            {
                temp->val = k;
                carry = 0;
            }
            // cout<<temp->val<<endl;
            temp = temp->next;
        }
        if(carry)
        {
            temp = head;
            while(temp->next) temp = temp->next;
            ListNode * tp = new ListNode(carry);
            temp->next = tp;
        }
        head = rev(head);
        return head;
    }
};