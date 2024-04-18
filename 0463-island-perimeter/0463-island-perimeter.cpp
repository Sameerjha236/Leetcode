class Solution {

    int check(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cord[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0;
        for (auto k : cord) {
            int x = k[0] + i, y = k[1] + j;
            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 0)
                ans++;
            else if (x < 0 || y < 0 || x >= m || y >= n)
                ans++;
        }
        return ans;
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j])
                    ans += check(i, j, grid);
            }
        }
        return ans;
    }
};