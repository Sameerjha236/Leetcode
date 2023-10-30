//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    bool dfs(int i, vector<int> &vis, vector<int> &path, vector<int> adj[])
    {
        vis[i] = 0;
        path[i] = 1;
        for(auto k: adj[i])
        {
            if(path[k])
                return 0;
            else if(vis[k] == 0) 
            {
                return 0;
            }
            bool ck = dfs(k,vis,path,adj);
            if(ck == 0) return 0;
        }
        vis[i] = 1;
        path[i] = 0;
        return 1;
    }
    
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        vector<int> vis(v,-1);
        vector<int> path(v,0);
        for(int i=0;i<v;i++)
        {
            if(adj[i].size() == 0) vis[i] = 1;
        }
        for(int i=0;i<v;i++)
        {
            if(vis[i] > -1) continue;
            dfs(i,vis,path,adj);
        }
        vector<int> ans;
        for(int i=0;i<v;i++)
        {
            if(vis[i]) ans.push_back(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends