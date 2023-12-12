class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), i = 0, j = 0;
        unordered_map<int,int> freq;

        while(j<n)
        {
            int curr = nums[j];
            freq[curr]++;
            while(freq[curr] > k)
            {
                int el = nums[i];
                freq[el]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};