class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        if(n==2)
            return 1;
        vector<int> ans(n,n+1);
        ans[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]==0)
                continue;
            for(int j=i+1;j<=i+nums[i] && j<n;j++)
            {
                ans[i] = min(ans[i],ans[j]+1);
            }
        }
        return ans[0];
    }
};