//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool helper(int node, vector<int> &vis, vector<int> adj[])
    {
        for(auto k: adj[node])
        {
            if(k == node) continue;
            if(vis[k] == -1)
            {
                vis[k] = ! vis[node];
                bool check = helper(k,vis,adj);
                if(!check) return false;
            }
            else if(vis[k] == vis[node]) return false;
        }
        return true;
    }

	bool isBipartite(int v, vector<int>adj[]){
	    vector<int> vis(v,-1);
	    for(int i=0;i<v;i++)
	    {
	        if(vis[i]>=0) continue;
	        vis[i] = 0;
	        bool check = helper(i,vis,adj);
	        if(!check) return false;
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends