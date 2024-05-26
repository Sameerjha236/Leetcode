#define ll long long int
class Solution {
    int mod = 1e9 + 7;
    ll helper(int n, int a, int l, vector<vector<vector<ll>>>& dp) {
        if (n == 0)
            return 1;
        if (dp[n][a][l] != -1)
            return dp[n][a][l];

        ll x = 0, y = 0, z = 0;

        x = helper(n - 1, a, 0, dp) % mod;

        if (a + 1 < 2) {
            y = helper(n - 1, a + 1, 0, dp) % mod;
        }

        if (l + 1 < 3) {
            z = helper(n - 1, a, l + 1, dp) % mod;
        }
        return dp[n][a][l] = ((x + y) % mod + z) % mod;
    }

public:
    int checkRecord(int n) {
        vector<vector<vector<ll>>> dp(n + 1,
                                      vector<vector<ll>>(2, vector<ll>(3, -1)));
        ll ans = helper(n, 0, 0, dp);
        return static_cast<int>(ans);
    }
};