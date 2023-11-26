class Solution {

    int solve(int i, int j, vector<vector<int>> & grid)
    {
        int m = grid.size(), n = grid[0].size();
        if(i>=m || j>=n || i<0 || j<0 || grid[i][j] == 0) return 0;

        grid[i][j] = 0;  

        int l = solve(i, j-1, grid);
        int r = solve(i, j+1, grid);
        int u = solve(i-1, j, grid);
        int d = solve(i+1, j, grid);

        int curr = l + r + u + d + 1;

        return curr;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int curr = solve(i, j, grid);
                ans = max(ans, curr);
            } 
        }
        return ans;
    }
};
