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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        vector<ListNode*> store;
        ListNode* temp = head;
        while(temp) {
            store.push_back(temp);
            temp=temp->next;
        }
        int n = store.size();
        if(n==1 || k%n ==0) return head;
        int st = n- k%n;
        int s=1;
        head=store[st];
        temp=head;
        while(s!=n)
        {
            st=(st+1)%n;
            s++;
            temp->next = store[st];
            temp = temp->next;
        }
        temp->next=nullptr;
        return head;
    }
};