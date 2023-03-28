class Solution {
public:

    int solve(vector<int>& days, vector<int>& costs,int i,vector<int> &dp)
    {
        int n=days.size();
        if(i>days[n-1]) return 0;
        if(dp[i]!=-1) return dp[i];
        int p = upper_bound(days.begin(),days.end(),i)- days.begin();
        int q = upper_bound(days.begin(),days.end(),i+6)-days.begin();
        int r = upper_bound(days.begin(),days.end(),i+29)-days.begin();
        int a = costs[0];
        if(p<n) a+=solve(days,costs,days[p],dp);
        int b = costs[1];
        if(q<n) b+=solve(days,costs,days[q],dp);
        int c = costs[2];
        if(r<n) c+=solve(days,costs,days[r],dp);
        dp[i] =  min(a,min(b,c));
        return dp[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(days[n-1]+1,-1);
        return solve(days,costs,days[0],dp);
    }
};