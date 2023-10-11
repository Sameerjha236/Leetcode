class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int> start,end;
        for(auto i:flowers)
        {
            start.push_back(i[0]);
            end.push_back(i[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        vector<int> ans;
        for(auto t:people)
        {
            int a = -1, b = -1;
            a = upper_bound(start.begin(),start.end(),t) - start.begin();
            b = lower_bound(end.begin(),end.end(),t) - end.begin();
            ans.push_back(a-b);
        }
        return ans;
    }
};
// 1 3 4 9 
// 6 7 12 13 
// 2 -> 1 0
// 3 -> 2 0
// 7 -> 3 2
// 11 out