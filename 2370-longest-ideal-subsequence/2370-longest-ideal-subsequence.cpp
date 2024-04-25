class Solution {
    int helper(int i, int prev, int k, vector<vector<int>>& dp, string& s) {
        if (i == s.size())
            return 0;
        if (dp[i][prev] != -1)
            return dp[i][prev];
        int tk = 0, nt = 0;
        if (prev == 0 || abs(prev - s[i]) <= k) {
            tk = 1 + helper(i + 1, s[i], k, dp, s);
        }

        nt = helper(i + 1, prev, k, dp, s);
        return dp[i][prev] = max(tk, nt);
    }

public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>('z' + 1, -1));
        int ans = helper(0, 0, k, dp, s);
        return ans;
    }
};