class Solution {

    int solve(int ind, int j, vector<vector<int>> &dp, vector<int> &vec)
    {
        if (j == 1)
        {
            int m = vec[ind];
            for (int i = ind + 1; i < vec.size(); i++) m = max(m, vec[i]);
            return m;
        }
        if (dp[ind][j] != -1) return dp[ind][j];

        int ans = INT_MAX, k = INT_MIN;

        for (int i = ind; i < vec.size() - j + 1; i++)
        {
            k = max(k, vec[i]);
            int curr = solve(i + 1, j - 1, dp, vec);
            ans = min(ans, curr + k);
        }

        return dp[ind][j] = ans;
    }

public:
    int minDifficulty(vector<int> &vec, int d)
    {
        int n = vec.size();
        if (n < d) return -1;
        else if (d == n)
        {
            int ans = 0;
            for (auto i : vec) ans += i;
            return ans;
        }

        vector<vector<int>> dp(n, vector<int>(d+1, -1));
        int ans = solve(0, d, dp, vec);
        return ans;
    }
};
