
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &adj)
    {
        queue<int> q;
        int n = adj.size();
        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++)
        {
            if(vis[i] >=0) continue;
            q.push(i);
            vis[i] = 0;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto k : adj[node])
                {
                    if (vis[k] == -1)
                    {
                        vis[k] = !vis[node];
                        q.push(k);
                    }
                    else if (vis[k] == vis[node])
                        return 0;
                }
            }
        }
        return 1;
    }
};