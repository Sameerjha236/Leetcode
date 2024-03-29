class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, m = g.size(), n = s.size();
        int i = 0, j = 0;
        while(i<m && j<n)
        {
            // cout<<g[i]<<" "<<s[j]<<endl;
            if(g[i]<=s[j])
            {
                ans++;
                i++;
                j++;
            }
            else j++;
        }
        return ans;
    }
};