class Solution {
public:

    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        int pos[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        grid[i][j] = 'C';
        // cout<<i<<" - "<<j<<endl;
        for(auto k:pos)
        {
            int r = i + k[0], c = j + k[1];
            if(r>=0 && c >=0 && r<grid.size() && c<grid[0].size() && grid[r][c] == 'O')
            {
                dfs(r,c,grid);
            }
        }
    }

    void solve(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        for(int j=0;j<n;j++)
        {
            if(grid[0][j] == 'O') dfs(0,j,grid);
        }
        for(int j=0;j<n;j++)
        {
            if(grid[m-1][j] == 'O') dfs(m-1,j,grid);
        }

        for(int j=0;j<m;j++)
        {
            if(grid[j][0] == 'O') dfs(j,0,grid);
        }
        for(int j=0;j<m;j++)
        {
            if(grid[j][n-1] == 'O') dfs(j,n-1,grid);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 'O') grid[i][j] = 'X';
                if(grid[i][j] == 'C') grid[i][j] = 'O';
            }
        }
    }
};