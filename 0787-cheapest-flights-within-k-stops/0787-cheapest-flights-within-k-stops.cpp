class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        // we do not take priority queue if we have uniform weight increase as here it is dependant on stops and it will always increase by one 
        vector<pair<int,int>> adj[n];
        for(auto l: flights)
        {
            int a = l[0], b = l[1], c = l[2];
            adj[a].push_back({b,c});
        }
        queue<pair<int, pair<int,int>>> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        // stops node weight
        q.push({0, {src,0}});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto k : adj[node])
            {
                int ed = k.first, w = k.second;
                if(dist[ed] > w + cost)
                {
                    dist[ed] = w + cost;
                    q.push({stops+1, {ed, dist[ed]}});
                }
            }
        }
        if(dist[dest] == 1e9) return -1;
        return dist[dest];
    }
};