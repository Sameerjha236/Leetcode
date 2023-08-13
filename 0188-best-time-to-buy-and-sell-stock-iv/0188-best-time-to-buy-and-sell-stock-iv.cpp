class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int trans = 1; trans <= k; trans++)
                {
                    int profit = 0;

                    if (buy)
                    {
                        int a = -prices[i] + dp[i + 1][0][trans];

                        int b = dp[i + 1][1][trans];

                        profit = max(a, b);
                    }
                    else
                    {
                        int a = prices[i] + dp[i + 1][1][ trans - 1];

                        int b = dp[i + 1][0][ trans];

                        profit = max(a, b);
                    }
                    dp[i][buy][trans] = profit;
                }
            }
        }

        return dp[0][1][k];
    }
};