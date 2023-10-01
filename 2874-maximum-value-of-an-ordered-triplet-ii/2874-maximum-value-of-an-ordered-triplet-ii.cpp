class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return 0;
        vector<int> pre(n,-1);
        vector<int> suf(n,-1);
        
        pre[0] = nums[0];
        for(int i=1;i<n;i++) pre[i] = max(nums[i],pre[i-1]);
        
        suf[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--) suf[i] = max(nums[i],suf[i+1]);
        long long ans = 0;
        
        for(int j=1;j<n-1;j++)
        {
            long long k = pre[j-1] - nums[j];
            long long curr = k * suf[j+1];
            if(curr>ans) ans = curr; 
        }
        return ans;

    }
};