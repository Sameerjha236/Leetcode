static bool comp(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b)
{
    if(a.first < b.first) return 1;
    if(a.first == b.first)
    {
        if(a.second.first > b.second.first) return 1;
    }

    return 0;
}
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<pair<int, pair<int,int>>> store;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                store.push_back({i+j, {i, nums[i][j]}});
            }
        }
        sort(store.begin(), store.end(), comp);
        vector<int> ans;
        for(auto i: store) ans.push_back(i.second.second);

        return ans;
    }
};