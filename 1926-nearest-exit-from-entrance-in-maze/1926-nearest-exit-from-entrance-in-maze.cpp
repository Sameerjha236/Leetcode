class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> store;
        int ans = 0,m = maze.size(), n =maze[0].size();
        store.push(make_pair(entrance[0],entrance[1]));
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> vis(m, vector<bool> (n,1));
        vis[entrance[0]][entrance[1]] = 0;
        while(!store.empty())
        {
            ans++;
            int k = store.size();
            while(k-->0)
            {
                int i = store.front().first;
                int j = store.front().second;
                store.pop();
                for(auto l:dir)
                {
                    int nR = i + l[0];
                    int nC = j + l[1];
                    if(nR>=0 && nC>=0 && nR<m && nC<n && maze[nR][nC] == '.' && vis[nR][nC])
                    {
                        if(nR == 0 || nC == 0 || nR == m-1 || nC == n-1) return ans;
                        vis[nR][nC] = false;
                        store.push(make_pair(nR,nC));
                    }
                }
            }
        }
        return -1;
    }
};