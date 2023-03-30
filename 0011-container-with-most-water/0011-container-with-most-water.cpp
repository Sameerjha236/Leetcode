class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int maximum=0;
        int l=0,r=height.size()-1;
        while(l<r)
        {
            int curr = (r-l) * min(height[l],height[r]);
            maximum = max(curr,maximum);
            if(height[l]<height[r]) l++;
            else r--;
        }
        return maximum;
    }
};