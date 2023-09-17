
class Solution
{
private:
    bool visited[105][105];
    int directions_x[4] = {0, 1, -1, 0};
    int directions_y[4] = {1, 0, 0, -1};
    int numRows, numCols;

public:
    void dfs(int x, int y, int limitEffort, vector<vector<int>> &heights)
    {
        if (visited[x][y])
            return;
        visited[x][y] = true;

        if (x == numRows - 1 && y == numCols - 1)
            return;
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + directions_x[i];
            int new_y = y + directions_y[i];

            if (new_x < 0 || new_x >= numRows || new_y < 0 || new_y >= numCols)
                continue;

            int newEffort = abs(heights[x][y] - heights[new_x][new_y]);
            if (newEffort <= limitEffort)
                dfs(new_x, new_y, limitEffort, heights);
        }
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        numRows = heights.size();
        numCols = heights[0].size();

        int lowerLimit = 0, upperLimit = 1e6;

        while (lowerLimit < upperLimit)
        {
            int mid = (upperLimit + lowerLimit) / 2;
            memset(visited, 0, sizeof visited);
            dfs(0, 0, mid, heights);

            if (visited[numRows - 1][numCols - 1])
                upperLimit = mid;
            else
                lowerLimit = mid + 1;
        }

        return lowerLimit;
    }
};