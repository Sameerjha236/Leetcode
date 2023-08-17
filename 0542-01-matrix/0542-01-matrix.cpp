
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, m + n + 1));
        queue<pair<int, int>> store;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                    if (i + 1 < m && mat[i + 1][j])
                    {
                        ans[i + 1][j] = 1;
                        store.push(make_pair(i + 1, j));
                    }
                    if (i - 1 >= 0 && mat[i - 1][j])
                    {
                        ans[i - 1][j] = 1;
                        store.push(make_pair(i - 1, j));
                    }
                    if (j + 1 < n && mat[i][j + 1])
                    {
                        ans[i][j + 1] = 1;
                        store.push(make_pair(i, j + 1));
                    }
                    if (j - 1 >= 0 && mat[i][j - 1])
                    {
                        ans[i][j - 1] = 1;
                        store.push(make_pair(i, j - 1));
                    }
                }
            }
        }
        while (!store.empty())
        {
            int i = store.front().first;
            int j = store.front().second;
            cout<<i<<" "<<j<<endl;
            store.pop();
            if (i + 1 < m && mat[i + 1][j])
            {
                if(ans[i+1][j] > ans[i][j]+1)
                {
                    ans[i+1][j] = ans[i][j]+1;
                    store.push(make_pair(i + 1, j));
                }
            }
            if (i - 1 >= 0 && mat[i - 1][j])
            {
                if(ans[i-1][j] > ans[i][j]+1)
                {
                    ans[i-1][j] = ans[i][j]+1;
                    store.push(make_pair(i - 1, j));
                }
            }
            if (j + 1 < n && mat[i][j + 1])
            {
                if(ans[i][j+1] > ans[i][j]+1)
                {
                    ans[i][j+1] = ans[i][j]+1;
                    store.push(make_pair(i , j+1));
                }
            }
            if (j - 1 >= 0 && mat[i][j - 1])
            {
                if(ans[i][j-1] > ans[i][j]+1)
                {
                    ans[i][j-1] = ans[i][j]+1;
                    store.push(make_pair(i , j-1));
                }
            }
        }
        return ans;
    }
};