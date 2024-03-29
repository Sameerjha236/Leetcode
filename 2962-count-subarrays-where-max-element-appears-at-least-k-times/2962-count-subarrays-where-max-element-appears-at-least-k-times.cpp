/*
[1,3,2,3,3,2,2,1] k = 2
5 + 5 + 4 + 4
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int i = 0, j = 0, mx = 0, freq = 0, n = nums.size();
        for(auto m:nums) mx = max(mx,m);

        while(j<n)
        {
            int curr = nums[j];
            if(curr == mx) freq++;
            while(freq == k)
            {
                ans += (n - j);
                if(nums[i] == mx) freq--;
                i++;
            }
            j++;
        }
        
        return ans;
    }
};