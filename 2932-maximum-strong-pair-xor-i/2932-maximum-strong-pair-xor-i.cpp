class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j = i;j<n;j++)
            {
                int x = nums[i], y = nums[j];
                if(abs(x - y) <= min(x,y))
                {
                    ans = max(ans, x ^ y);
                }
            }
        }
        return ans;
    }
};