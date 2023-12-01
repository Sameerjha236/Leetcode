class Solution {
    void solve(int a, int b, string ds, vector<string> &ans)
    {
        if(a == 0 && b == 0)
        {
            ans.push_back(ds);
            return;
        }
        if(a)
        {
            ds.push_back('(');
            // cout<<a<<" "<<b<<
            solve(a-1,b,ds,ans);
            ds.pop_back();
        }
        if(a<b && b)
        {
            ds.push_back(')');
            solve(a,b-1,ds,ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds;
        solve(n,n,ds,ans);
        return ans;
    }
};