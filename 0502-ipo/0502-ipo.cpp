#define pr pair<int,int>
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> maxProfit;
        priority_queue<pr,vector<pr>,greater<pr>> minCap;
        int n=profits.size();
        for(int i=0;i<n;i++)
            minCap.push(make_pair(capital[i],profits[i]));
        for(int i=0;i<k;i++)
        {
            while(minCap.empty()!=true && minCap.top().first<=w)
            {
                maxProfit.push(minCap.top().second);
                minCap.pop();
            }
            if(maxProfit.empty())
                break;
            w+=maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};