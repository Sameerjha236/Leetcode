class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& p) {
        vector<pair<int,int>> vec;
        for(auto i:p) vec.push_back({i[0],i[1]});
        sort(vec.begin(), vec.end());
        int ans = 0;
        for(int i=0;i<vec.size()-1;i++)
            ans = max(ans,vec[i+1].first - vec[i].first);
        return ans;
    }
};