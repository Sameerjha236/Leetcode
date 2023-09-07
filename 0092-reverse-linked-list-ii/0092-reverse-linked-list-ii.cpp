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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        int len = 0;
        ListNode * st=nullptr, *curr=head, *end = nullptr;
        
        while(len+1<left)
        {
            len++;
            st = curr;
            curr = curr->next;
        }
        len = 0;
        curr=head;
        while(len<right)
        {
            len++;
            curr = curr->next;
        }
        end = curr;
        if(st)
            curr = st->next;
        else curr = head;
        ListNode * prev = end, * forw = nullptr;
        while(curr->next != end)
        {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        curr->next = prev;
        if(st)
            st->next = curr;
        else head = curr;
        return head;
    }
};