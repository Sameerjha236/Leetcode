#define ll long long 
class Solution {
public:
    bool check(int curr,vector<int> &piles, int h)
    {
        ll int k=0;
        for(auto i:piles)
        {
            if(i%curr==0) k+=i/curr;
            else k+=(i/curr)+1;
        }
        return k<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(low<=high)
        {
            int m = (low+high)/2;
            if(check(m,piles,h))
            {
                ans = min(ans,m);
                high=m-1;
            }
            else
                low=m+1;
        }
        return ans;
    }
};