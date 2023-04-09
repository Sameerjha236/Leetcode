class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp (m,vector<int> (m,-1));
        dp[0][0] = triangle[0][0];
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<i;j++)
            {
                int a=INT_MAX,b=INT_MAX;
                a = dp[i-1][j];
                if(j-1>=0) b = dp[i-1][j-1];
                dp[i][j] = triangle[i][j] +min(a,b); 
            }
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        } 
        int ans=INT_MAX;
        for(int i=0;i<m;i++)
            ans = min(ans,dp[m-1][i]);
        return ans;
    }
};