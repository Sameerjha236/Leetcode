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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head = list1, *end = list2, *l = nullptr, *r = nullptr;
        while (end->next)
            end = end->next;
        int k = 0;
        while (k <= b) {
            if (k == a - 1)
                l = list1;
            if (k == b)
                r = list1->next;
            k++;
            list1 = list1->next;
        }
        l->next = list2;
        end->next = r;
        return head;
    }
};