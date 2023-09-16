class Solution {
public:
    int partitionString(string s) {
        set<char> store;
        int ans =0, n=s.size();
        for(int i=0;i<n;i++)
        {
            char k = s[i];
            if(store.find(k) == store.end())
            {
                store.insert(k);
            }
            else
            {
                store.clear();
                ans++;
                store.insert(k);
            }
        }
        return ans+1;
    }
};