class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> st(26,0);
        for(auto i:s) st[i-'a']++;
        string ans;
        for(auto c: order)
        {
            while(st[c-'a']) {
                st[c-'a']--;
                ans += c;
            }
        }
        for(auto c: s)
        {
            if(order.find(c) == string::npos)
            {
                ans += c;
            }
        }
        return ans;
    }
};