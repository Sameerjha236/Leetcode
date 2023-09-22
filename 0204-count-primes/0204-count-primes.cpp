class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n+1,1);
        isPrime[0] = isPrime[1] = 0;
        int cnt = 0;
        for(int i = 2 ; i < n ; i++)
        {
            if(isPrime[i])
            {
                cnt++;
                for(int j = 2*i; j < n; j += i)
                {
                    isPrime[j] = 0;
                }
            }
        }
        return cnt;
    }
};