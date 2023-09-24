//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool dfs(int node, vector<bool> &vis, vector<bool> &path, vector<bool> &check, vector<int> adj[])
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
  
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
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