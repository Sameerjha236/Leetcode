class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s, s2 = s;
        reverse(s2.begin(),s2.end()); 
	    int m = s1.size(), n = s2.size();
        int ma = 0;
	    int c[m + 1][n + 1];
	    memset(c, 0, sizeof(c));
	    for (int i = 1; i <= m; i++)
	    {
	    	for (int j = 1; j <= n; j++)
	    	{
	    		if (s1[i - 1] == s2[j - 1])
	    		{
	    			c[i][j] = c[i - 1][j - 1] + 1;
	    			ma = max(ma, c[i][j]);
	    		}
	    		else
	    			c[i][j] = max(c[i - 1][j], c[i][j - 1]);
	    	}
	    }
	    return ma;
    }
};