class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n=a.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(m == 0)
            {
                if(a[0]>a[1]) return 0;
                else l=m+1;
            }
            else if(m==n-1)
            {
                if(a[m]>a[m-1]) return m;
                else r = m-1;
            }
            else
            {
                if(a[m]>a[m-1] && a[m]>a[m+1]) 
                    return m;
                else if(a[m]<a[m+1])
                {
                    l = m+1;
                }
                else r = m-1;
            }
        }
        return 0;
    }
};