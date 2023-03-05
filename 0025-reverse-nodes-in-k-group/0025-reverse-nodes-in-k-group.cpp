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
class Solution
{
private:
    ListNode *helper(ListNode *head, int k, ListNode *prev)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *curr = head, *forw = nullptr;

        while (k-- && curr)
        {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        head = prev;
        return head;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head, *prev = nullptr, *mprev = nullptr;
        for (int i = 0; temp != nullptr;)
        {
            if (i % k == 0)
            {
                ListNode *tp = temp;
                int b = 0;
                while (tp && b < k)
                {
                    b++;
                    tp = tp->next;
                }
                if (b != k)
                    break;
                ListNode *h = temp;
                prev = temp;
                for (int j = 0; prev != nullptr && j < k; j++)
                    prev = prev->next;
                if (i == 0)
                    head = helper(temp, k, prev);
                else
                    h = helper(temp, k, prev);
                if (mprev && h)
                    mprev->next = h;
                mprev = temp;
                i += k;
            }
            else
                i++;
            temp = temp->next;
        }
        return head;
    }
};