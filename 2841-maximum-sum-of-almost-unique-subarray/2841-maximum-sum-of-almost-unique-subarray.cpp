class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<long long int,long long int> store;
        long long int i=0,j=0,n=nums.size(),ans=0,curr=0;

        while(j<n)
        {
            curr += nums[j];
            store[nums[j]]++;
            if(j-i+1<k)
            {
                j++;
                continue;
            }
            if(store.size() >= m)
                ans = max(ans,curr);
            store[nums[i]]--;
            if(store[nums[i]] <= 0)
                store.erase(nums[i]);
            curr -= nums[i];
            i++;
            j++;
        }
        
        return ans;
    }
};