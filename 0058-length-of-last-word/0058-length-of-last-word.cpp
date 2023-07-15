class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,n=s.size();
        bool a=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]==32)
            {
                if(a)
                {
                    return ans;
                }
            }
            else
            {
                a=1;
                ans++;
            }
        }
        return ans;
    }
};