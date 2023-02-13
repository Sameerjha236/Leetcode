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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode * temp=head,*forw=head->next;
        while(head!=nullptr && head->next!=nullptr)
        {
            if(head->val == forw->val)
            {
                head->next=forw->next;
                forw=head->next;
            }
            else
            {
                head=head->next;
            }
        }
        return temp;
    }
};