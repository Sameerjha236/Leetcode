class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int k = money - prices[0] - prices[1];
        if(k<0) return money;
        return k;
    }
};