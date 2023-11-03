class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dr[]={0,0,-1,1,-1,1,-1,1};
        int dc[]={-1,1,0,0,-1,1,1,-1};
        if(grid[0][0]==1)
        {
            return -1;
        }
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[0][0]=0;
        q.push({0,{0,0}});
        while(!q.empty())
        {
            int x=q.front().second.first;
            int y=q.front().second.second;
            int cost=q.front().first;
            if(x==n-1 && y==m-1)
            {
                return cost+1;
            }
            q.pop();
            for(int i=0;i<8;i++)
            {
                int r=x+dr[i];
                int c=y+dc[i];
                if(r>=0 && c>=0 && r<n && c<n && dis[r][c]>cost+1 && grid[r][c]==0)
                {
                    dis[r][c]=cost+1;
                    q.push({cost+1,{r,c}});
                }
            }
        }
        return -1;
    }
};