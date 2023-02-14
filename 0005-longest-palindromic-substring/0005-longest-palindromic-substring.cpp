class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),ans=1;
        bool dp[n][n];
        memset(dp,0,sizeof(dp));
        // i index denotes start and j denotes end index
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }   
        int start = 0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                ans = 2;
                start = i;
            }
        }

        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j= i+k-1;

                if(s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j]=1;
                    if(k>ans)
                    {
                        ans=k;
                        start=i;
                    }
                }
            }
        }
        string t;
        for(int i=start;i<start+ans;i++)
        {
            t+=s[i];
        }
        return t;
    }
};