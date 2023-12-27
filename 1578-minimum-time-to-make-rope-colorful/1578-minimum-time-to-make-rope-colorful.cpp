class Solution {
public:
    int minCost(string colors, vector<int>& vec) {
        int ans = 0, n = colors.size();
        for(int i=0;i<n-1;i++)
        {
            if(colors[i] == colors[i+1])
            {
                ans += min(vec[i], vec[i+1]);
                vec[i+1] = max(vec[i], vec[i+1]);
            }
        }
        return ans;
    }
};