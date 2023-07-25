class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> st;
        for(auto i:nums) st[i]++;
        for(auto i:st)
        {
            pq.push(make_pair(i.second,i.first));
        }
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};