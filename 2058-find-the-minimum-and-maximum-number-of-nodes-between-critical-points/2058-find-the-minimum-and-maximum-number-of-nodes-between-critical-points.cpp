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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        int pre = 0, k = 0;
        pre = head->val;
        head = head->next;

        while (head->next && head) {
            int curr = head->val;
            int forw = head->next->val;
            if ((curr > forw && curr > pre) || (curr < pre && curr < forw)) {
                ans.push_back(k);
            }

            pre = curr;
            k++;
            head = head->next;
        }
        if (ans.size() < 2)
            return {-1, -1};
        int mn = INT_MAX, mx = -1;
        mx = ans[ans.size() - 1] - ans[0];
        for (int i = 0; i < ans.size() - 1; i++) {
            int a = ans[i], b = ans[i + 1];
            mn = min(b - a, mn);
        }
        return {mn, mx};
    }
};