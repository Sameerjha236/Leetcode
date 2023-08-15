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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        vector<ListNode *> small,large;
        ListNode * tail=head;
        while(tail)
        {
            if(tail->val < x) small.push_back(tail);
            else large.push_back(tail);
            tail = tail->next;
        }
        tail=nullptr,head= nullptr;
        for(int i=0;i<small.size();i++)
        {
            if(!head)
            {
                head = tail = small[i];
            }
            else
            {
                tail->next = small[i];
                tail = tail->next;
            }
            tail->next = nullptr;
        }

        for(int i=0;i<large.size();i++)
        {
            if(!head)
            {
                head = tail = large[i];
            }
            else
            {
                tail->next = large[i];
                tail = tail->next;
            }
            tail->next = nullptr;
        }

        return head;
    }
};