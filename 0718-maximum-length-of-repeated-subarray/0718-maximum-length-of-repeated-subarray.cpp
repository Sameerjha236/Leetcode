class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int arr[m+1][n+1],mx=0;
        memset(arr,0,sizeof(arr));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    arr[i][j]=arr[i-1][j-1]+1;
                    mx=max(arr[i][j],mx);
                }
                else
                    arr[i][j]=0;
            }
        }
        return mx;
    }
};