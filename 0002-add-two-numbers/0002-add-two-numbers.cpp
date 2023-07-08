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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * l3=nullptr,*temp=nullptr;
        int c=0;
        while(l1 || l2)
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
            if(c) c--;
            if(k>9) c++;
            ListNode * hs = new ListNode(k>9 ? k-10 : k);
            if(!l3) {
                l3 = temp = hs;
            }
            else {
                temp->next = hs;
                temp = temp->next;
            }
        }
        if(c)
        {
            ListNode * hs = new ListNode(c);
            temp->next = hs;
        }
        return l3;
    }
};