class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int,int>> row(m);
        vector<pair<int,int>> col(n);

        for(int i=0;i<m;i++)
        {
            int z = 0, o = 0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]) o++;
                else z++;
            }
            row[i] = {o,z};
        }

        for(int i=0;i<n;i++)
        {
            int z = 0, o = 0;
            for(int j=0;j<m;j++)
            {
                if(grid[j][i]) o++;
                else z++;
            }
            col[i] = {o,z};
        }

        vector<vector<int>> ans(m, vector<int> (n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a = row[i].first, b = row[i].second;
                int c = col[j].first, d = col[j].second;
                ans[i][j] = a + c - b - d;
            }
        }
        return ans;
    }
};