class Solution {
public:

    bool dfs(int node, vector<bool> &vis, vector<bool> &path, vector<bool> &check, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        path[node] = 1;
        for(auto k:adj[node])
        {
            if(vis[k] && path[k]) return true;
            else if(vis[k]) continue;
            bool c= dfs(k,vis,path,check,adj);
            if(c) return true; 
        }
        check[node] = 1;
        path[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> vis(n,0);
        vector<bool> path(n,0);
        vector<bool> check(n,0);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,path,check,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(check[i]) ans.push_back(i);
        }
        return ans;
    }
};