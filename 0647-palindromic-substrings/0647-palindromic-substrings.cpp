class Solution {
public:
    
    int solve(int l, int r, string &s)
    {
        int n = s.size();
        int curr=0;
        while(l>=0 && r<n && s[l] == s[r])
        {
            curr++;
            l--;
            r++;
        }
        return curr;
    }

    int countSubstrings(string s) {
        int ans = 0, n = s.size();

        for(int i=0;i<n;i++)
        {
            int a = solve(i,i,s);
            int b = solve(i,i+1,s);

            ans += a + b;
        }


        return ans;
    }
};