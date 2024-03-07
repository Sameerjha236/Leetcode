class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        vector<int> y(3,0),  ny(3,0);
        int n = grid.size();
        int c = n/2;
        for(int i=0;i<c;i++)
        {
            int a = grid[i][i];
            int b = grid[i][n-1-i];
            y[a]++;
            y[b]++;
            grid[i][i] = grid[i][n-1-i] = -1;
        }
        for(int j=c;j<n;j++)
        {
            int k = grid[j][c];
            y[k]++;

            grid[j][c] = -1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) if(grid[i][j] != -1) ny[grid[i][j]]++;
        }
        
        int ans = 0;
        vector<pair<int,int>> l, r;
        for(int i=0;i<=2;i++)
        {
            l.push_back({y[i],i});
            r.push_back({ny[i],i});
        }
        sort(l.begin(),l.end());
        sort(r.begin(),r.end());
        if(l[2].second == r[2].second)
        {
            if((l[2].first - l[1].first)<=(r[2].first- r[1].first))
            {
                ans += (l[0].first + l[2].first);
                ans += (r[0].first + r[1].first);
            }
            else
            {
                ans += (l[0].first + l[1].first);
                ans += (r[0].first + r[2].first);
            }
            return ans;
        }
        for(int i=0;i<=1;i++)
        {
            ans += l[i].first;
            ans += r[i].first;
        }

        return ans;
    }
};
