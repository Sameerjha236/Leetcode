
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int ans = 0, total = 0, m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> store;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    total++;
                else if (grid[i][j] == 2)
                    store.push(make_pair(i, j));
            }
        }
        if (total == 0)
            return 0;
        int curr = 0;
        while (!store.empty())
        {
            ans++;
            int k = store.size();
            for (int f = 0; f < k; f++)
            {
                int i = store.front().first;
                int j = store.front().second;
                store.pop();
                // left
                if (j - 1 >= 0 && grid[i][j - 1] == 1)
                {
                    grid[i][j - 1] = 2;
                    store.push(make_pair(i, j - 1));
                    curr++;
                }
                // right
                if (j + 1 < n && grid[i][j + 1] == 1)
                {
                    grid[i][j + 1] = 2;
                    store.push(make_pair(i, j + 1));
                    curr++;
                }

                // up
                if (i + 1 < m && grid[i + 1][j] == 1)
                {
                    grid[i + 1][j] = 2;
                    store.push(make_pair(i + 1, j));
                    curr++;
                }

                // down
                if (i - 1 >= 0 && grid[i - 1][j] == 1)
                {
                    grid[i - 1][j] = 2;
                    store.push(make_pair(i - 1, j));
                    curr++;
                }
            }
        }
        if (curr < total)
            return -1;
        return ans - 1;
    }
};