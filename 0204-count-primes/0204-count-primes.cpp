class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> check(n,1);
        check[1] = 0;
        int ans = 0;
        for(int i=2;i<n;i++)
        {
            if(check[i] == 0) continue;
            else ans++;
            int j=2;
            while(j*i<n)
            {
                check[i*j] = 0;
                j++;
            }
        } 
        return ans;
    }
};