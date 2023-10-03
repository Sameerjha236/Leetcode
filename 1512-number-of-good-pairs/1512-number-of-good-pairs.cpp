class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> store;
        for(auto i:nums) store[i]++;
        int ans = 0;
        for(auto i:store)
        {
            if(i.second>=2)
            {
                int curr = (i.second * (i.second-1) )/2;
                ans += curr;
            }
        }
        return ans;
    }
};