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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        // head
        ListNode * forw = head->next,*curr=head,*prev=nullptr;
        curr->next = forw->next;
        forw->next = curr;
        head = forw;
        //rest node
        prev = curr;
        cout<<prev->val<<endl;
        curr = curr->next;
        while(curr!=nullptr && curr->next!=nullptr)
        {
            cout<<curr->val<<" "<<curr->next->val<<endl;
            forw = curr->next;
            prev->next = forw;
            curr->next = forw->next;
            forw->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};