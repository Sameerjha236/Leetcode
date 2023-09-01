class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[0][0] || grid[m-1][n-1]) return -1;
        if(m == 1 && n == 1 ) return 1;
        queue<pair<int,int>>store;
        store.push(make_pair(0,0));
        vector<vector<bool>> vis(m, vector<bool> (n,1));
        vis[0][0] = 0;
        int ans = 0;
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {-1,1}, {1,-1}, {-1,-1}};
        while(!store.empty())
        {
            int k = store.size();
            ans++;
            while(k--)
            {
                int i = store.front().first;
                int j = store.front().second;
                store.pop();
                if(i == m-1 && j == n-1) return ans;
                for(auto l:dir)
                {
                    int nR = i + l[0];
                    int nC = j + l[1];

                    if(nR >= 0 && nC >= 0 && nR<m && nC<n && vis[nR][nC] && grid[nR][nC] == 0)
                    {
                        vis[nR][nC] = 0;
                        store.push(make_pair(nR,nC));
                    }
                }
            }
        }
        return -1;
    }
};