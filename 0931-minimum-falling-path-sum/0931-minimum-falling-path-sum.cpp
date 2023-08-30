class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int j = 0; j < n; j++)
        {
            dp[m - 1][j] = matrix[m - 1][j];
        }
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int down = INT_MAX, left = INT_MAX, right = INT_MAX;
                down = dp[i + 1][j];
                if(j-1 >= 0)
                    left = dp[i + 1][j - 1];
                if(j+1 < n)
                    right = dp[i + 1][j + 1];

                dp[i][j] = min(down, min(left, right)) + matrix[i][j];
            }
        }
        for (int j = 0; j < n; j++)
            ans = min(ans, dp[0][j]);
        return ans;
    }
};