class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<pair<int,int>> cord = {{0,1},{0,-1}, {1,0}, {-1,0}};
        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> dist(m, vector<int> (n,INT_MAX));
        
        dist[0][0] = 0;
        q.push({0, {0,0}});
        
        while(!q.empty())
        {
            int cost = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            
            for(auto k: cord)
            {
                int x = r + k.first;
                int y = c + k.second;
                
                if(x>=0 && y>=0 && x<m && y<n)
                {
                    int val = abs(grid[x][y] - grid[r][c]);
                    val = max(val, cost);
                    
                    if(val < dist[x][y])
                    {
                        dist[x][y] = val;
                        q.push({val, {x,y}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};