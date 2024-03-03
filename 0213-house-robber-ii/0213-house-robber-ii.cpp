class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int dp[n + 1][2];
        memset(dp, 0, sizeof(dp));

        dp[n - 1][0] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            for (int chk = 0; chk <= 1; chk++) {
                int tk = 0, nt = 0;
                if (i == 0) {
                    tk = dp[i + 2][1] + nums[i];
                    nt = dp[i + 1][0];
                } else {
                    tk = nums[i] + dp[i + 2][chk];
                    nt = dp[i + 1][chk];
                }
                dp[i][chk] = max(tk, nt);
            }
        }

        return max(dp[0][0], dp[0][1]);
    }
};