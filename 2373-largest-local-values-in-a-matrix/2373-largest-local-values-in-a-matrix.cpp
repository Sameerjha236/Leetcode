class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));

        int maxi = INT_MIN;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (grid[i + k][j + l] > maxi)
                            maxi = grid[i + k][j + l];
                    }
                }
                ans[i][j] = maxi;
                maxi = 0;
            }
        }

        return ans;
    }
};