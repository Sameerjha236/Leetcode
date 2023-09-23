class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int arr[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n,1));
        queue<pair<int,int>> store;
        vis[sr][sc] = 0;
        store.push(make_pair(sr,sc));

        while(!store.empty())
        {
            int r = store.front().first;
            int c = store.front().second;
            store.pop();
            for(auto i:arr)
            {
                int rx = r + i[0], rc = c + i[1];
                if(rx>=0 && rc>=0 && rx<m && rc<n && grid[rx][rc] == grid[r][c] && vis[rx][rc])
                {
                    store.push(make_pair(rx,rc));
                    vis[rx][rc] = 0;
                }
            }
            grid[r][c] = color;
        }
        return grid;
    }
};