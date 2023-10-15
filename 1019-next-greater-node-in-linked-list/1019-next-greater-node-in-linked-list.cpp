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
    vector<int> nextLargerNodes(ListNode* head) {
        int n=0;
        ListNode * tp = head;
        while(tp)
        {
            tp = tp->next;
            n++;
        }
        vector<int> ans(n,0);
        stack<pair<int,int>> store;
        int i = 0;
        while(head)
        {
            int k = head->val;
            head = head->next;
            while(!store.empty() && store.top().first < k)
            {
                ans[store.top().second] = k;
                store.pop();
            }
            store.push( make_pair(k,i));
            i++;
        }
        return ans;
    }
};