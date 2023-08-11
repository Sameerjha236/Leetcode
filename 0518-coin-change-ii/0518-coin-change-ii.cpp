class Solution {
public:

    int solve(int ind, int amt, vector<int> &coins, vector<vector<int>> &dp)
    {
        if(amt<0) return 0;
        if(amt == 0) return 1;
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int ans = 0;
        for(int i=ind;i<coins.size();i++)
        {
            int curr = solve(i,amt-coins[i],coins,dp);
            ans += curr;
        }
        return dp[ind][amt] = ans;
    }

    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp (n,vector<int> (amt+1,-1));
        int ans = solve(0,amt,coins,dp);

        return ans;
    }
};