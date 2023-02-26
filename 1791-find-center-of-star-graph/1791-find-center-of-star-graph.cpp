class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n =edges.size()+1;
        vector<int> adj[n+1];
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n+1;i++)
        {
            if(adj[i].size()==n-1)
                return i;
        }
        return 0;
    }
};