class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> hash;
        for(auto i: nums) hash[i]++;
        vector<vector<int>> ans;
        for(auto x: hash)
        {
            int k = x.first, f = x.second;
            for(int i=0;i<f;i++)
            {
                if(i<ans.size()) ans[i].push_back(k);
                else
                {
                    vector<int> tp;
                    tp.push_back(k);
                    ans.push_back(tp);
                }
            }
        }
        return ans;
    }
};