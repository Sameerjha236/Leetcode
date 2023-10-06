class Solution {
public:
    int integerBreak(int n) {
       if(n == 2) return 1;
       if(n == 3) return 2;
       if(n == 4) return 4;
       int ans = 1;
       while(n)
       {
           if(n == 4)
            {
                ans *= 4;
                break;
            }
            else if(n>=3)
            {
                n-=3;
                ans *= 3;
            }
            else
            {
                n -= 2;
                ans *= 2;
            }
       }
       return ans;  
    }
};