class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for(auto i: left)
        {
            ans = max(ans,i);
        }
        for(auto i: right)
        {
            int curr = n - i ;
            ans = max(ans,curr);
        }
        return ans;
    }
};