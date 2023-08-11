class Solution {
public:

    int solve(vector<int> &coins, int amt, vector<int> &dp)
    {
        if(amt == 0) return 0;
        if(amt <0) return INT_MAX;
        if(dp[amt]!=-1) return dp[amt];
        int ans = INT_MAX;
        for(auto i:coins)
        {
            int curr = solve(coins,amt-i,dp);
            if(curr!=INT_MAX) ans = min(curr+1,ans);
        }
        return dp[amt] = ans;
    }

    int coinChange(vector<int>& coins, int amt) {
        if(!amt) return 0;
        vector<int> dp(amt+1,-1);
        int ans = solve(coins,amt,dp);
        if(ans == INT_MAX) return -1;   
        return ans;
    }
};