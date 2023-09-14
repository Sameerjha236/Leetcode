class Solution {
public:

    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj)
    {
        if(vis[node]) return;
        vis[node] = 1;
        int n = adj.size();
        for(int i=0;i<n;i++)
        {
            if(adj[node][i])
                dfs(i,vis,adj);
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            ans ++;
            dfs(i,vis,adj);
            cout<<endl;
        }
        return ans;
    }
};