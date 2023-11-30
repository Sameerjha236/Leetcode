class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0, j = 1, n = nums.size(), ans = 0;

        while(j<n)
        {
            // cout<<nums[i]<<" "<<nums[j]<<" ";
            if(nums[j] - nums[i]>k)
            {
                // cout<<"1\n";
                i = j;
                j++;
                ans++;
            }
            else 
            {
                // cout<<"2\n";
                j++;
            }
        }
        return ans+1;
    }
};