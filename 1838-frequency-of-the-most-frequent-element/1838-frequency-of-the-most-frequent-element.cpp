class Solution {
public:
    int maxFrequency(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        int ans = 1, n = nums.size();

        for(int i=n-1;i>=0;i--)
        {
            if(i < n-1 && nums[i] == nums[i+1]) continue;
            int curr = 1, k = t;
            // cout<<i<<" "<<nums[i]<<endl;
            for(int j = i-1;j>=0;j--)
            {
                if(nums[j] == nums[i])
                {
                    curr++;
                    // cout<<"a\n";
                }
                else
                {
                    if(nums[i] - nums[j] <=k)
                    {
                        curr++;
                        k = k - (nums[i] - nums[j]);
                        // cout<<"b\n";
                    }
                    else break;
                }
            }
            ans = max(ans,curr);

        }

        return ans;
    }
};