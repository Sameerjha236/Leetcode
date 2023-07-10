class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> jumps(n,-1);
        jumps[n-1]=0;
        for(int i=n-1;i>0;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(abs(nums[j]-nums[i])<=target)
                {
                    if(jumps[i]!=-1)
                    jumps[j] = max(jumps[j],jumps[i]+1);
                }
            }
        }
        return jumps[0];
    }
};