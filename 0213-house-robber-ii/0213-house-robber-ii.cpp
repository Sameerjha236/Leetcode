class Solution {
    int helper(int i, int chk, int dp[][2], vector<int>& nums) {
        int n = nums.size(), tk = 0, nt = 0;
        if (i >= n)
            return 0;
        if (dp[i][chk] != -1)
            return dp[i][chk];
        if (i == 0) {
            tk = helper(i + 2, 1, dp, nums) + nums[i];
            nt = helper(i + 1, 0, dp, nums);
        } else if (i == n - 1) {
            if (chk)
                return 0;
            return nums[i];
        } else {
            tk = nums[i] + helper(i + 2, chk, dp, nums);
            nt = helper(i + 1, chk, dp, nums);
        }
        return dp[i][chk] = max(tk, nt);
    }

public:
    int rob(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int dp[n][2];
        memset(dp, -1, sizeof(dp));
        ans = helper(0, 0, dp, nums);
        return ans;
    }
};