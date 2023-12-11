class Solution {
    int sx = -1, sy = -1;
    int dx = -1, dy = -1;
    int w = 0;
    
    int solve(int i, int j, vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if(i>= m || j>=n || i<0 || j<0) return 0;
        
        if(grid[i][j] == -1) return 0;
        
        if(i == dx && j == dy && w == -1) return 1;

        int cord[4][2] = {{0,1},{0,-1}, {1,0}, {-1,0}};
        int ans = 0;
        for(auto k: cord)
        {
            int x = i + k[0], y = j + k[1];
            grid[i][j] = -1;
            w--;
            int curr = solve(x,y,grid);
            ans += curr;
            w++;
            grid[i][j] = 0;
        }
        return ans;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    sx = i;
                    sy = j;
                }
                else if(grid[i][j] == 2)
                {
                    dx = i;
                    dy = j;
                }
                else if(grid[i][j] == 0) w++;
            }
        }

        int ans = 0;
        ans = solve(sx,sy,grid);
        return ans;
    }
};