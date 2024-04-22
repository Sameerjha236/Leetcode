class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {
        vector<int> adj[n];
        for (auto k : edges) {
            int a = k[0], b = k[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<int> q;
        vector<int> vis(n, 0);
        vector<int> rest(n, 0);
        for (auto k : restricted)
            rest[k] = 1;

        vis[0] = 1;
        q.push(0);
        while (!q.empty()) {
            int curr = q.front();
            // cout<<curr<<" -> ";
            q.pop();
            for (auto k : adj[curr]) {
                // cout<<k<<" ";
                if (rest[k] || vis[k])
                    continue;
                vis[k] = 1;
                q.push(k);
            }
            // cout<<endl;
        }
        
        int ans = 0;
        for (auto k : vis)
            if (k)
                ans++;
        return ans;
    }
};