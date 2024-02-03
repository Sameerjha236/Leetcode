class Solution {
public:
    int ans(int i, int k, vector<int>& arr, vector<int>& dp) {
        if (i >= arr.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int maxi = -1e9, len = 0, maxAns = -1e9;
        int l = arr.size() > i + k ? i + k : arr.size();
        for (int j = i; j < l; j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + ans(j + 1, k, arr, dp);
            maxAns = max(sum, maxAns);
        }
        return dp[i] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return ans(0, k, arr, dp);
    }
};