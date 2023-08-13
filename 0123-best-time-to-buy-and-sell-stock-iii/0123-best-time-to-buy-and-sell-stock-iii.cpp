
class Solution
{
public:
    int solve(int i, int buy, int trans, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (i == prices.size())
            return 0;
        if (trans == 0)
            return 0;
        if (dp[i][buy][trans] != -1)
            return dp[i][buy][trans];
        int profit = 0;

        if (buy)
        {
            int a = -prices[i] + solve(i + 1, 0, trans, prices, dp);

            int b = solve(i + 1, 1, trans, prices, dp);

            profit = max(a, b);
        }
        else
        {
            int a = prices[i] + solve(i + 1, 1, trans - 1, prices, dp);

            int b = solve(i + 1, 0, trans, prices, dp);

            profit = max(a, b);
        }

        return dp[i][buy][trans] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int trans = 1; trans <= 2; trans++)
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

        return dp[0][1][2];
    }
};