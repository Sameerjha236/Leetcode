class Solution {
public:

    void solve(int n, int ind,int k,int r ,vector<int> &ds, vector<vector<int>> &ans)
    {
        if(ds.size() == k)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<=n-r+1;i++)
        {
            ds.push_back(i);
            solve(n,i+1,k,r-1,ds,ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(n,1,k,k,ds,ans);
        return ans;
    }
};