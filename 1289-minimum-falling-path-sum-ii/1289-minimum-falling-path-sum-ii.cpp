class Solution {

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int ans = INT_MAX;
                for (int c = 0; c < n; c++) {
                    if (c == j)
                        continue;
                    ans = min(ans, dp[i - 1][c]);
                }
                dp[i][j] = ans + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for (auto k : dp[m - 1])
            ans = min(ans, k);
        return ans;
    }
};