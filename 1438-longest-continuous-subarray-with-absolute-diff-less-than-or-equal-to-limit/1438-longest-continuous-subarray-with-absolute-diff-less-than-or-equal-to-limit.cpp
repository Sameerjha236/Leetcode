
class Solution
{
public:
    int longestSubarray(vector<int> &nums, int k)
    {
        multiset<std::pair<int, int>> store;
        int n = nums.size(), ans = 0, i = 0, j = 0;

        while (j < n)
        {
            store.insert({nums[j], j});
            int a = (*store.begin()).first, b = (*store.rbegin()).first;

            while (abs(a - b) > k)
            {
                store.erase({nums[i], i});
                a = (*store.begin()).first;
                b = (*store.rbegin()).first;
                i++;
            }

            ans = max(ans, static_cast<int>(store.size()));
            j++;
        }

        return ans;
    }
};