class Solution {
public:

    bool check(string s)
    {
        int n = s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i] != s[n-i-1])
                return false; 
        }
        return true;
    }

    void solve(string s, int ind, vector<string> &ds,vector<vector<string>> &ans)
    {
        if(ind == s.size())
        {
            ans.push_back(ds);
            return;
        }
        string curr;
        for(int i=ind;i<s.size();i++)
        {
            curr +=s[i];
            if(check(curr))
            {
                ds.push_back(curr);
                solve(s,i+1,ds,ans);
                ds.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(s,0,ds,ans);
        return ans;
    }
};