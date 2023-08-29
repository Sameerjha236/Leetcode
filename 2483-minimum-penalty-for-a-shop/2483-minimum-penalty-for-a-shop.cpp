class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int yT=0, nT=0;
        for(int i=0;i<n;i++)
        {
            if(customers[i] == 'Y') yT++;
            else nT++;
        } 
        int a=0,b=0,ans=-1,val=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int curr = b + (yT - a);
            if(customers[i] == 'Y') a++;
            else b++;
            if(curr < val)
            {
                ans = i;
                val = curr;
            }
        }
        int curr = b - (yT - a);
        if(curr < val) ans = n;
        return ans;
    }
};