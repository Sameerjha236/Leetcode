class Solution {
public:

    void solve(int ind, int k, int n, vector<int> ds, vector<vector<int>> &ans)
    {
        if(n == 0 && k==0)
        {
            ans.push_back(ds);
            return;
        }
        if(n<0) return;
        if(k<0) return;
        if(ind > 9) return;

        for(int i=ind;i<=9;i++)
        {
            ds.push_back(i);
            solve(i+1,k-1,n-i,ds,ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,k,n,ds,ans);
        return ans;
    }
};