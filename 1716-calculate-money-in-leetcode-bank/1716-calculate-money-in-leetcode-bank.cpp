class Solution {
public:
    int totalMoney(int n) {
        int d = 0, ans = 0, pre = 0, m = 0;
        while(d<n)
        {
            int curr = 0;
            if(d%7 == 0)
            {
                pre = m + 1;
                m++;
                curr = pre;
            }
            else
            {
                pre++;
                curr = pre;
            }
            ans += curr;
            d++;
        }
        return ans;
    }
};