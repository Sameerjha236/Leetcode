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
    ListNode* sortList(ListNode* head) {
        vector<pair<int,ListNode *>> store;
        while(head)
        {
            store.push_back(make_pair(head->val,head));
            head = head->next;
        } 
        sort(store.begin(),store.end());
        head = nullptr;
        ListNode *tail = nullptr;
        for(auto i:store)
        {
            if(tail==nullptr)
            {
                head = tail = i.second;
            }
            else
            {
                tail->next = i.second;
                tail = i.second;
            }
            tail->next =nullptr;
        }
        return head;
    }
};