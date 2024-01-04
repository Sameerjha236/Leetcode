long long int lCM(long long int a, long long int b) {
    return (a * b) / std::gcd(a, b);
}
class Solution {
public:
    int minimizeSet(int d1, int d2, int u1, int u2) {
        int ans = INT_MAX;

        long long int l = 1, r = 1e10;
        while(l<=r)
        {
            long long int m = (l+r)/2;
            long long int a = m - m/d1;
            long long int b = m - m/d2;
            long long int c = m - m/d1 - m/d2 + m/lCM(d1,d2);
            if(a>=u1 && b>= u2 && a + b - c>= u1 + u2)
            {
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans == INT_MAX ?  -1 :  ans;
    }
};