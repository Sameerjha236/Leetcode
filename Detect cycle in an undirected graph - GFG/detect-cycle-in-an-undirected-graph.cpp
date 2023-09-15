//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int> vis(v,0);
        queue<pair<int,int>> store;
        
        for(int i=0;i<v;i++)
        {
            if(vis[i]) continue;
            store.push(make_pair(i,-1));
            
            while(!store.empty())
            {
                int node = store.front().first;
                int parent = store.front().second;
                store.pop();
                
                if(vis[node]) return true;
                vis[node] = 1;
                
                for(auto it: adj[node])
                {
                    if(it == parent) continue;
                    store.push(make_pair(it,node));
                }
            }
            
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends