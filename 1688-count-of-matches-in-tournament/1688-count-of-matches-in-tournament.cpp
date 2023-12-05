class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(n>1)
        {
            if(n%2)
            {
                n = n/2;
                ans += n;
                n++;
            }
            else
            {
                n = n/2;
                ans +=n;
            }
        }
        return ans;
    }
};