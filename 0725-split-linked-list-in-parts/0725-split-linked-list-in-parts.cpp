
class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans;
        if (!head)
        {
            while (k--)
                ans.push_back(nullptr);
            return ans;
        }
        ListNode *temp = head;
        int n = 0;
        while (temp)
        {
            temp = temp->next;
            n++;
        }
        if (k >= n)
        {
            temp = head;
            ListNode *curr = head;
            while (ans.size() < k)
            {
                if (temp)
                    curr = temp->next;
                else
                    curr = nullptr;
                ans.push_back(temp);
                if (temp)
                    temp->next = nullptr;
                temp = curr;
            }
            return ans;
        }

        int box = n / k, extra = n % k, c = 1;
        temp = head;
        while (temp)
        {
            if (c == 1)
            {
                ans.push_back(temp);
            }
            if (c == box)
            {
                if (extra)
                {
                    extra--;
                    ListNode *curr = temp->next->next;
                    temp->next->next = nullptr;
                    temp = curr;
                }
                else
                {
                    ListNode *curr = temp->next;
                    temp->next = nullptr;
                    temp = curr;
                }
                c = 1;
            }
            else
            {
                temp = temp->next;
                c++;
            }
        }
        return ans;
    }
};