class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        int pre[n], suff[n], curr = nums[0];
        for(int i=0;i<n;i++)
        {
            pre[i] = curr;
            curr = min(curr,nums[i]);
        }
        curr = nums[n-1];
        for(int i=n-1;i>=0;i--)
        {
            suff[i] = curr;
            curr = min(curr,nums[i]);
        }
        int ans = INT_MAX;
        for(int i=1;i<n-1;i++)
        {
            int a = pre[i], b = suff[i];
            curr = nums[i];
            if(a < curr && curr > b)
                ans = min(ans,a+b+curr);
        }
        if(ans == INT_MAX) ans = -1;
        return ans;
    }
};