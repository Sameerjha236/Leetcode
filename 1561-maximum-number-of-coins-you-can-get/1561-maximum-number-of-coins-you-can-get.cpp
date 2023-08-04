class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int> ());
        int ans=0,n=piles.size(),req=n/3;
        for(int i=1;i<n-req;i+=2)
        {
            ans += piles[i];
        }
        return ans;
    }
};