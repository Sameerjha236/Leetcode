class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        vector<int> adj[n];
        for(auto i: edges)
        {
            int a = i[0], b = i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> vis(n,1);
        queue<int> q;
        q.push(src);
        vis[src] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(node == dst) return true;
            for(auto k: adj[node])
            {
                if(vis[k])
                {
                    vis[k] = 0;
                    q.push(k);
                }
            }
        }
        return false;
    }
};