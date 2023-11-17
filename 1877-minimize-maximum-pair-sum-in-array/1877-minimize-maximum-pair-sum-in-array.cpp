class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN, n = nums.size();
        for(int i=0;i<n/2;i++)
        {
            ans = max(ans, nums[i]+ nums[n-1-i]);
            // cout<<nums[i]<<" "<<nums[i+n/2]<<endl;
        }
        return ans;
    }
};