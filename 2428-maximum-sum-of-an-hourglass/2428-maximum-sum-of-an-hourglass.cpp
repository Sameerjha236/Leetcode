class Solution {
public:

    int helper(int i, int j, int m, int n, vector<vector<int>> & grid)
    {
        int curr=0;
        if(i+2<m && j+2<n)
        {
            int a = grid[i][j];
            int b = grid[i][j+1];
            int c = grid[i][j+2];
            int d = grid[i+1][j+1];
            int e = grid[i+2][j];
            int f = grid[i+2][j+1];
            int g = grid[i+2][j+2];
            curr = a + b+ c+ d+ e+ f+ g;
        }
        return curr;
    }

    int maxSum(vector<vector<int>>& grid) {
        int ans = 0,m = grid.size(),n = grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int curr = helper(i,j,m,n,grid);
                ans = max(curr,ans);
            }
        }
        return ans;
    }
};