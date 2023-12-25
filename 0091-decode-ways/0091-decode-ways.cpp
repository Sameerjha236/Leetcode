class Solution {

    int solve(int i, string ds,vector<vector<int>> &dp, string &s)
    {
        int n = s.size();
        int k = 0;
        if(ds.size())
            k = stoi(ds);

        if(k>26)
            return 0;
        if(i == n)
            return 1;
        if(dp[i][k] != -1) return dp[i][k];
        
        string curr = ds;
        curr += s[i];
        int c = stoi(curr);
        int p = 0, q = 0;
        
        if(c<=26 && c)
        {
            if(curr.size() == 2)
            {
                p = solve(i+1,"",dp,s);
            }
            else
            {
                p = solve(i+1,curr,dp,s);
            }
        }
        
        if(c && k && s[i] !='0')
        {
            string st;
            st += s[i];
            q = solve(i+1,st,dp,s);
        }

        return dp[i][k] = p + q;
    }

public:
    int numDecodings(string s) {
        int ans = 0, n = s.size();
        string ds;
        vector<vector<int>> dp(n, vector<int> (27,-1));
        ans = solve(0,ds,dp,s);
        return ans;
    }
};