class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(auto i:nums) sum += i;
        if(x>sum) return -1;
        if(sum == x) return nums.size();
        int req = sum - x;
        int i=0,j=0,n = nums.size(),ans = INT_MAX,curr=0;
        while(i<n && j<n)
        {
          curr += nums[j];
          while(i<n && curr >= req)
          {
              if(req == curr)
              {
                  int k = j - i + 1;
                  ans = min(ans,n - k);
              }
              curr -=nums[i];
              i++;
          }
          j++;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};