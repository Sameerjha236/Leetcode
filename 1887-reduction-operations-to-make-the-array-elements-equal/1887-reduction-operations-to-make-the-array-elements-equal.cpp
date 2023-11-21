class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> hash;
        for(auto i: nums)
            hash[i]++;

        vector<pair<int,int>> store;
        for(auto i: hash)
        {
            store.push_back({i.first, i.second});
        }

        int ans = 0, n = store.size();
        // for(auto i:store) cout<<i.first<<" "<<i.second<<endl;
        for(int i=n-1;i>0;i--)
        {
            ans += store[i].second;
            // cout<<store[i].first<<" "<<store[i].second<<endl;
            store[i-1].second += store[i].second;
        }

        return ans;
    }
};