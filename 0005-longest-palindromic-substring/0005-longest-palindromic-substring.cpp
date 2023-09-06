class Solution {
public:

    int helper(string &s,int l, int r)
    {
        while(l>=0 && r<s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r-l-1;
    }

    string longestPalindrome(string s) {
        string ans;
        int len = 1,st=0;
        for(int i=0;i<s.size() - 1; i++)
        {
            int odd = helper(s,i,i);
            int even = helper(s,i,i+1);
            int curr = max(odd,even);

            if(curr>len)
            {
                len = curr;
                st = i - (curr-1)/2;
            }
        }
        ans = s.substr(st,len);
        return ans;
    }
};