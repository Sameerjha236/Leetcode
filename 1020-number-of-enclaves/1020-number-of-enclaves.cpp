class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(),total = 0, ans =0;
        queue<pair<int,int>> store;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!grid[i][j]) continue;
                total++;
                if(i == 0 ||i == m-1 || j==0 || j == n-1)
                {
                    store.push(make_pair(i,j));
                    grid[i][j] = 0;
                }    
            }
        }
        while(!store.empty())
        {
            int i = store.front().first;
            int j = store.front().second;
            store.pop();
            grid[i][j] = 0;
            total--;
            if(i+1<m && grid[i+1][j])
            {
                store.push(make_pair(i+1,j));
                grid[i+1][j] = 0;
            } 
            if(j+1<n && grid[i][j+1]) 
            {
                store.push(make_pair(i,j+1));
                grid[i][j+1] = 0;
            }
            if(j-1>=0 && grid[i][j-1]) 
            {
                store.push(make_pair(i,j-1));
                grid[i][j-1] = 0;
            }
            if(i-1>=0 && grid[i-1][j]) 
            {
                store.push(make_pair(i-1,j));
                grid[i-1][j] = 0;
            }
        }

        return total;
    }
};