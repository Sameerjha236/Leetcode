class Solution {
    int dp[50][50][50][50];

    int solve(int r, int c, int x, int y, vector<vector<int>> &grid)
    {
        int n = grid.size();
        if(r>=n || x>= n || c>=n || y>=n || grid[x][y] == -1 || grid[r][c] == -1) return -1e8;
        if(r == n-1 && c == n-1)
        {
            return grid[r][c];
        }
        if(dp[r][c][x][y] != -1) return dp[r][c][x][y];
        int cherry = 0;
        if(r == x && c == y)
            cherry = grid[r][c];
        else cherry = grid[r][c] + grid[x][y];
        int f1 = solve(r,c+1,x,y+1,grid);// h h
        int f2 = solve(r,c+1,x+1,y,grid);// h v
        int f3 = solve(r+1,c,x+1,y,grid);// v v
        int f4 = solve(r+1,c,x,y+1,grid);// v h
        cherry += max(max(f1,f2), max(f3,f4));
        return dp[r][c][x][y] = cherry;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,0,0,grid);
        return max(ans,0);
    }
};