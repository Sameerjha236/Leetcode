class Solution {
public:
    bool isPowerOfFour(int n) {
        long long int i = 1;
        while(i<=n)
        {
            if(i == n) return 1;
            i = i * 4;
        }
        return 0;
    }
};