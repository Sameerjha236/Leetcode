class Solution {
public:
    int reverse(int x) {
        bool sign=0;
        long long int k=0;
        if(x<0)
        {
            if(x<= -1 * pow(2,31)) return 0;
            sign = 1;
            x *=-1;
        }
        vector<long long int> ans;
        while(x)
        {
            ans.push_back(x%10);
            x /=10;
        }
        for(int i=0;i<ans.size();i++)
        {
            k += ans[i] * pow(10,ans.size()-1-i);
        }
        if(sign) k *=-1;
        if(k > pow(2,31)-1 || k < -1 * pow(2,31)) return 0;
        return k;
    }
};