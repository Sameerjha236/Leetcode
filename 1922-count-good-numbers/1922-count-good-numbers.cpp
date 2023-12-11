class Solution {
public:
    long long k = 1000000007;
    long long p(long long x,long long n){
        if(n==0) return 1;
        long long temp=p(x,n/2);

        if(n%2 ==0) return (temp*temp)%k;
        else return (temp*temp*x)%k;
        
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd =n/2;
        long long f= p(5,even)%k;
        long long s=p(4,odd)%k;
        return (int)((f*s)%k);
    }
    
};