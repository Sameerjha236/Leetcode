class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        vector<pair<int,int>> cord = {{0,1}, {0,-1}, {1,0}, {-1,0} ,{1,1}, {1,-1},{-1,1},{-1,-1}};
        vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
        queue<pair<int, pair<int,int>>> q;
        
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        
        while(!q.empty())
        {
            int cost = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            if(x == n-1 && y == n-1) return cost;
            
            for(auto k: cord)
            {
                int a = x + k.first;
                int b = y + k.second;
                
                if(a>=0 && b>=0 && a<n && b<n && grid[a][b]==0 && dist[a][b] > cost + 1)
                {
                    dist[a][b] = cost + 1;
                    q.push({cost+1, {a,b}});
                }
            }
        }
        return -1;
    }
};