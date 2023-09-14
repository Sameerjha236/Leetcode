class Solution {
public:

    void dfs(int i, int j, vector<vector<char>> &grid,vector<vector<int>> &pos)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return;
        if(grid[i][j] == '0') return;

        grid[i][j] = '0';
        for(int k=0;k<4;k++)
        {
            dfs(i+pos[k][0],j+pos[k][1],grid,pos);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<int>> pos = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    dfs(i,j,grid,pos);
                }
            }
        }

        return ans;
    }
};