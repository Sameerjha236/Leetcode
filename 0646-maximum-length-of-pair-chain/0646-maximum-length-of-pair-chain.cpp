class Solution {
public:

    static bool comp(vector<int> a, vector<int> b)
    {
        return a[1]<b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(),pairs.end(),comp);
        int cur = INT_MIN, ans = 0;
        
        for (const auto& pair : pairs) {
            if (cur < pair[0]) {
                cur = pair[1];
                ans++;
            }
        }
        return ans;
    }
};