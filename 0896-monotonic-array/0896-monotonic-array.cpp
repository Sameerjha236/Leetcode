class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i = 0, n = nums.size();
        while(i<n-1)
        {
            if(nums[i] <= nums[i+1])
            {
                i++;
            }
            else break;
        }
        if(i == n-1) return 1;
        i = 0;
        while(i<n-1)
        {
            if(nums[i]>=nums[i+1])
            {
                i++;
            }
            else break;
        }
        if(i == n-1) return 1;
        return 0;
    }
};