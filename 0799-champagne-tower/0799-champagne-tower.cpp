class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>dp(101, 0);
        dp[0] = (double) poured;
        for (int i = 0; i < query_row; i++) 
        {
            for (int j = i; j >= 0; j--)
            {
                if (dp[j] > 1) 
                {
                    double overFlow = (dp[j] - 1.0) / 2.0;
                    dp[j+1] += overFlow;
                    dp[j] = overFlow;
                } 
                else {
                    dp[j] = 0;
                }
            }
        }
        return min(1.0, dp[query_glass]);
    }
};