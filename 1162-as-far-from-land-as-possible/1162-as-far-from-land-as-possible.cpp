class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> store;
        int n=grid.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    store.push(make_pair(i,j));
            }
        }
        int ans=-1;
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!store.empty())
        {
            int r = store.front().first;
            int c = store.front().second;
            ans = grid[r][c];

            store.pop();
            for(auto i:dir)
            {
                int nr = r+i[0];
                int nc = c+i[1];
                if(min(nr,nc)>=0 && max(nr,nc)<n && grid[nr][nc]==0)
                {
                    store.push(make_pair(nr,nc));
                    grid[nr][nc] = grid[r][c]+1;
                }
            }

        }
        if(ans<=1)
            return -1;
        return ans-1;
    }
};