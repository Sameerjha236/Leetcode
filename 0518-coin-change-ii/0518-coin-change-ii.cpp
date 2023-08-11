
class Solution
{
public:
    int f(int ind, int k, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (k % coins[0] == 0)
                return 1;
            return 0;
        }
        if (dp[ind][k] != -1)
            return dp[ind][k];
        int notpick = f(ind - 1, k, coins, dp);
        int pick = 0;
        if (coins[ind] <= k)
            pick = f(ind, k - coins[ind], coins, dp);
        return dp[ind][k] = pick + notpick;
    }
    int change(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);

        return ans;
    }
};