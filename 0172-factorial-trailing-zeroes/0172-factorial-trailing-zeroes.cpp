class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        for(int i=5;i<=n;i+=5)
        {
            int k = i;
            while(k>=5 && k%5 == 0)
            {
                k /= 5;
                ans++;
            }
        }
        return ans;
    }
};