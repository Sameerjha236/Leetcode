class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0, n = s.size();
        string res;
        for(int i=0;i<=n-1;i++)
        {
            int a = solve(i,i,s);//odd
            int p = (a-1)*2 + 1;
            int b = solve(i,i+1,s);//even
            int q = b*2;


            if(p>=q && p>ans)
            {
                res = s.substr(i - a + 1,p);

                ans = p;
            }
            else if(q>ans)
            {
                res = s.substr(i-b+1,q);

                ans = q;
            }

        }

        return res;
    }

    int solve(int l, int r, string &s)
    {
        int n = s.size();
        int k = 0;
        while(l>=0 && r<n && s[l] == s[r])
        {
            l--;
            r++;
            k++;
        }
        return k;
    }
};