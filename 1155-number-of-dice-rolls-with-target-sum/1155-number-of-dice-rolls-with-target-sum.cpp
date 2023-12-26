class Solution {
    int mod = 1e9 + 7;
    int solve(int curr, int n, int k, int target,vector<vector<int>> &dp)
    {
        if(curr == target)
        {
            if(n == 0)
            return 1;
            else return 0;
        } 
        if(curr> target) return 0;
        if(n == 0) return 0;
        if(dp[curr][n] != -1) return dp[curr][n];
        int ans = 0;
        for(int i=1;i<=k;i++)
        {
            int tp = solve(i+curr,n-1,k,target,dp);
            
            ans += tp;
            ans = ans % mod;
        }
        ans = ans % mod;
        return  dp[curr][n] = ans;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        int ans = 0;
        vector<vector<int>> dp(10001, vector<int> (n+1,-1));
        ans = solve(0,n,k,target,dp);
        return ans;
    }
};