class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0,curr=0;
        set<int> st;
        int i=0,j=0,n=nums.size();
        while(j<n)
        {
            while(st.count(nums[j]))
            {
                st.erase(nums[i]);
                curr -= nums[i];
                i++;
            }
            st.insert(nums[j]);
            curr +=nums[j];
            if(j-i+1 < k)
            {
                j++;
            }
            else
            {
                ans = max(ans,curr);
                curr -=nums[i];
                st.erase(nums[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
