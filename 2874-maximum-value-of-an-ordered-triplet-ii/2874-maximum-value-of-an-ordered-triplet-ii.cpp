class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int pre[n], suff[n], curr = 0;
        for(int i=0;i<n;i++)
        {
            pre[i] = curr;
            curr = max(curr,nums[i]);
        }
        curr = nums[n-1];
        suff[n-1] = 0;
        for(int i=n-2;i>=0;i--)
        {
            suff[i] = curr;
            curr = max(curr,nums[i]);
        }

        long long ans;
        for(int i=1;i<n-1;i++)
        {
            int a = pre[i];
            int b = suff[i];
            long long int c = (a - nums[i]);
            c *= b;
            ans = max(c,ans);
        }
        return ans;
    }
};