class Solution {

    bool check(int k, vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        
        vector<pair<int,int>> cord = {{0,1},{0,-1},{-1,0},{1,0}};
        vector<vector<bool>> vis(m, vector<bool> (n,1));
        queue<pair<int,int>> q;
        
        vis[0][0] = 0;
        q.push({0,0});

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            if(r == m-1 && c == n-1) return 1;
            q.pop();
            for(auto z: cord)
            {
                int x = r + z.first;
                int y = c + z.second;
                if(x>=0 && y>=0 && x<m && y<n && vis[x][y] && abs(grid[x][y] - grid[r][c]) <= k)
                {

                    vis[x][y] = 0;
                    q.push({x,y});
                }
            }
        }
        return 0;
    }

public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int ans = 0, l = 0, r = 1e6;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(check(m,grid))
            {
                ans = m;
                r = m-1;
            } 
            else
            {
                l = m+1;
            } 
        }
        return ans;
    }
};