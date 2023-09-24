class Solution {
public:

    bool check(string p, string q)
    {
        int i=0,l=0,k=0;
        int j=p.size()-1, r=q.size()-1;
        while(i<=j && l<=r && k!=p.size())
        {
            if(p[i] == q[l])
            {
                k++;
                i++;
            } 
            if(p[j] == q[r] && k!=p.size())
            {
                k++;
                j--;
            } 
            l++;
            r--;
        }
        return k == p.size();
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        for(auto c:words)
        {
            if(check(c,s)) ans++;
        }
        return ans;
    }
};