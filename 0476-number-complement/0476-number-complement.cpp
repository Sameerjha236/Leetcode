class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        // num = num>>1;
        for(int i=0;num;i++)
        {
            int curr = !(num&1) * pow(2,i);
            ans+=curr;
            num = num>>1;
        }
        return ans;
    }
};