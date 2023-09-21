class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        if(total % 2)
        {
            int pos = total / 2 + 1;
            int i=0,j=0;
            // cout<<pos<<endl;
            while(pos)
            {
                int a = INT_MAX, b = INT_MAX,k=0;
                if(i<m) a = nums1[i];
                if(j<n) b = nums2[j];
                if(a<b)
                {
                    i++;
                    k = a;
                }
                else
                {
                    j++;
                    k = b;
                }
                pos--;
                if(pos == 0) return k;
            }
        }
        else
        {
            int p1 = total/2, p2 = total/2 + 1;
            int i=0,j=0,curr = 0;
            while(curr<total)
            {
                int a = INT_MAX, b = INT_MAX,k=0;
                if(i<m) a = nums1[i];
                if(j<n) b = nums2[j];
                if(a<b)
                {
                    i++;
                    k = a;
                }
                else
                {
                    j++;
                    k = b;
                }
                curr++;
                if(curr == p1 || curr == p2) ans += k;
            }
            ans /= 2;
        }
        return ans;
    }
};