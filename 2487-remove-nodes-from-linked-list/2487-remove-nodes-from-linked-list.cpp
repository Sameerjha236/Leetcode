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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        while (head) {
            int k = head->val;
            while (!st.empty() && st.top()->val < k) {
                st.pop();
            }
            st.push(head);
            head = head->next;
        }
        ListNode* tail = nullptr;
        while (!st.empty()) {
            ListNode* curr = st.top();
            curr->next = tail;
            st.pop();
            tail = curr;
        }
        return tail;
    }
};