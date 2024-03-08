class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> mp(101, 0);
        int k = 0;
        for (auto i : nums) {
            mp[i]++;
            k = max(mp[i], k);
        }
        int res = 0;
        for (auto i : mp)
            if (i == k)
                res += i;

        return res;
    }
};