class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end());
        if(n == 1) return cost[0];
        else if(n<=3) return cost[n-1] + cost[n-2];

        int ans = 0, i = n-1 ;
        while(i>0)
        {
            ans += cost[i] + cost[i-1];
            i -= 3;
        }
        if(i == 0) ans += cost[0];
        return ans;  

    }
};