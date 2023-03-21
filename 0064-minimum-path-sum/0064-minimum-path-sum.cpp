class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int l=INT_MAX,r=INT_MAX;
                if(i) l = dp[i-1][j];
                if(j) r = dp[i][j-1];

                dp[i][j] = min(l,r) + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};