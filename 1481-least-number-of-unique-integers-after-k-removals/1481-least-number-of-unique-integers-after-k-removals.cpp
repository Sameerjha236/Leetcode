class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> hash;
        for(auto i:arr) hash[i]++;

        vector<pair<int,int>> vec;
        for(auto i:hash) vec.push_back({i.second,i.first});
        sort(vec.begin(),vec.end());
        int ans = vec.size();
        for(auto cur:vec)
        {
            int a = cur.first, b = cur.second;
            if(a<=k)
            {
                k -= a;
                ans--;
            }
            else break;
        }

        return ans;
    }
};