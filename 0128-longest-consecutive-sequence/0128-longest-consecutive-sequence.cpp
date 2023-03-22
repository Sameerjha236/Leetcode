class Solution {
public:
    int longestConsecutive(vector<int>& vec) {
        if(vec.size()==0)
            return 0;
        set<int> store;
        for(auto i:vec)
        {
            store.insert(i);
        }
        int ans=1,curr=0,prev;
        bool b=0;
        for(auto i:store)
        {
            if(b==0)
            {
                prev=i;
                curr++;
                b=1;
                continue;   
            }
            if(prev+1 == i)
            {
                curr++;
            }
            else
            {
                curr=1;
            }
            prev=i;
            ans = max(ans,curr);
        }
        return ans;
    }
};