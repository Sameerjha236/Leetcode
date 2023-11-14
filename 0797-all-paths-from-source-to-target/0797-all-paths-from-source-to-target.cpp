class Solution {

    void solve(int i, int &end, vector<int> ds, vector<vector<int>> &ans,vector<vector<int>>& adj)
    {
        ds.push_back(i);
        if(i == end)
        {
            ans.push_back(ds);
            return;
        }
        for(auto k: adj[i])
        {
            solve(k,end,ds,ans,adj);
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = adj.size()-1;
        solve(0,n,ds,ans,adj);

        return ans;
    }
};